#include "matrix.h"

#define J1_ULMT  150 //��1�֐ߊp�x���~�b�g ������
#define J1_LLMT -150 //��1�֐ߊp�x���~�b�g ������
#define J2_ULMT  120 //��2�֐ߊp�x���~�b�g ������
#define J2_LLMT  -60 //��2�֐ߊp�x���~�b�g ������
#define J3_ULMT  120 //��3�֐ߊp�x���~�b�g ������
#define J3_LLMT -110 //��3�֐ߊp�x���~�b�g ������
#define J4_ULMT   90 //��4�֐ߊp�x���~�b�g ������
#define J4_LLMT  -90 //��4�֐ߊp�x���~�b�g ������
#define J5_ULMT   90 //��5�֐ߊp�x���~�b�g ������
#define J5_LLMT  -90 //��5�֐ߊp�x���~�b�g ������

#define ON  1
#define OFF 0

#define PREPARE 0
#define MANU_OPE 1
#define SYS_OPE  2

int mani_data[5];
double JointAngle[6]={0,0,0,0,0,0};

unsigned char StrategyStart=OFF;
unsigned char ModeControl = PREPARE;
unsigned char StrategyNumber=0;
unsigned char senddat2=0x24;
int mouse_x,mouse_y,AD_Data[3]={0};
int io_status;


HANDLE hCommW;     //�V���A���|�[�g�̃n���h�� 
DWORD writesize1,readsize;  //�|�[�g�֏������񂾃o�C�g��,�ǂݍ��񂾃o�C�g�� 


// �{�[���[�g�ݒ胊�X�g Host-PC - �⏕��� �ł�9600���g�p���Ă���
typedef enum {       
    br2400  = 2400, 
    br4800  = 4800,
    br9600  = 9600,  //����g�p���Ă���{�[���[�g
    br19200 = 19200,
    br31250 = 31250,
    br38400 = 38400,
    br57600 = 57600
} BaudRate;



#define AXIS_L 0.1
#define H0 0.3
#define H1 0.25
#define H2 0.16
#define H3 0.07
#define H4 0.08

struct  matrix  T;
double  LINK_PARAMETERS[8][4];


//�����N�p�����[�^�̏�����
//�ڕW�֐ߊp�x�Ȃǂ���������
void init_link_parameters( void )
{
	int i, j;

	for( i=0; i<8; i++ )
    	for( j=0; j<4; j++ )  LINK_PARAMETERS[i][j] = 0.0;

		LINK_PARAMETERS[0][2] = H0;
		LINK_PARAMETERS[2][1] = M_PI/2.0;
		LINK_PARAMETERS[3][0] = H1;
		LINK_PARAMETERS[4][0] = H2;
        LINK_PARAMETERS[5][1] = M_PI/2.0;
		LINK_PARAMETERS[6][2] = H3+H4;
}

//�����ϊ��s��̐���
void ht( struct matrix *mat, double a, double alpha, double d, double theta )
{
	mat->data[0][0] = cos(theta);            mat->data[0][1] =-sin(theta);            mat->data[0][2] = 0.0;           mat->data[0][3] = a;
	mat->data[1][0] = cos(alpha)*sin(theta); mat->data[1][1] = cos(alpha)*cos(theta); mat->data[1][2] =-sin(alpha);    mat->data[1][3] =-sin(alpha)*d;
	mat->data[2][0] = sin(alpha)*sin(theta); mat->data[2][1] = sin(alpha)*cos(theta); mat->data[2][2] = cos(alpha);    mat->data[2][3] = cos(alpha)*d;
	mat->data[3][0] = 0.0;                   mat->data[3][1] = 0.0;                   mat->data[3][2] = 0.0;           mat->data[3][3] = 1.0;
}

//����W�̕\��
void reference_frame( void )
{
	setcolor( 0xFF );   	kik_line3D( 0.0, 0.0, 0.0, 2.0*AXIS_L, 0.0, 0.0 );
	setcolor( 0xFF00 ); 	kik_line3D( 0.0, 0.0, 0.0, 0.0, 2.0*AXIS_L, 0.0 );
	setcolor( 0xFF0000 ); 	kik_line3D( 0.0, 0.0, 0.0, 0.0, 0.0, 2.0*AXIS_L );
}


//�e�֐߂̈ʒu�ɍ��W����\������֐�
void object_frame( double *origin, double *x, double *y, double *z )
{
	setcolor( 0xFF ); 
	kik_line3D( origin[0], origin[1], origin[2], origin[0]+AXIS_L*(x[0]-origin[0]), origin[1]+AXIS_L*(x[1]-origin[1]), origin[2]+AXIS_L*(x[2]-origin[2]) );
	setcolor( 0xFF00 );
	kik_line3D( origin[0], origin[1], origin[2], origin[0]+AXIS_L*(y[0]-origin[0]), origin[1]+AXIS_L*(y[1]-origin[1]), origin[2]+AXIS_L*(y[2]-origin[2]) );
	setcolor( 0xFF0000 );
	kik_line3D( origin[0], origin[1], origin[2], origin[0]+AXIS_L*(z[0]-origin[0]), origin[1]+AXIS_L*(z[1]-origin[1]), origin[2]+AXIS_L*(z[2]-origin[2]) );
}


#define HAND_LENGTH 0.1
//�n���h�����̍��W�������\���֐�
void robot_hand( struct matrix mat )
{
	double  vector[2][4], temp[4];
	/*** left hand ***/
	temp[0] = 0.0;  temp[1] =-HAND_LENGTH/2.0;      temp[2] =-HAND_LENGTH/2.0;      temp[3] = 1.0;
	matrix_multiplication_mv( vector[0], mat, temp );
	temp[0] = 0.0;  temp[1] =-HAND_LENGTH/2.0;      temp[2] = HAND_LENGTH/2.0;      temp[3] = 1.0;
	matrix_multiplication_mv( vector[1], mat, temp );
	setcolor( 0xFFFF00 ); kik_line3D( vector[0][0], vector[0][1], vector[0][2], vector[1][0], vector[1][1], vector[1][2] );
	
	/*** right hand ***/
	temp[0] = 0.0;  temp[1] = HAND_LENGTH/2.0;      temp[2] =-HAND_LENGTH/2.0;      temp[3] = 1.0;
	matrix_multiplication_mv( vector[0], mat, temp );
	temp[0] = 0.0;  temp[1] = HAND_LENGTH/2.0;      temp[2] = HAND_LENGTH/2.0;      temp[3] = 1.0;
	matrix_multiplication_mv( vector[1], mat, temp );
	setcolor( 0x000000 ); kik_line3D( vector[0][0], vector[0][1], vector[0][2], vector[1][0], vector[1][1], vector[1][2] );

	/*** base ***/
	temp[0] = 0.0;  temp[1] = HAND_LENGTH/2.0;      temp[2] =-HAND_LENGTH/2.0;      temp[3] = 1.0;
	matrix_multiplication_mv( vector[0], mat, temp );
	temp[0] = 0.0;  temp[1] =-HAND_LENGTH/2.0;      temp[2] =-HAND_LENGTH/2.0;      temp[3] = 1.0;
	matrix_multiplication_mv( vector[1], mat, temp );
	setcolor( 0x000000 ); kik_line3D( vector[0][0], vector[0][1], vector[0][2], vector[1][0], vector[1][1], vector[1][2] );
}

//�w�肵���ԍ��̋�Ԃœ����ϊ��̐ς��s���֐��D���{�b�g�n���h�ʒu�\�����Ɏg�p
void ht2( int num1, int num2, struct matrix *mat )
{
	int i, j, k;
	double  origin[4][3], x[4], y[4], z[4];
	struct  matrix A[2];
	
	for( i=0; i<2; i++ ) matrix_alloc( A+i, 4, 4 );

	ht( mat, LINK_PARAMETERS[num1][0], LINK_PARAMETERS[num1][1], LINK_PARAMETERS[num1][2], LINK_PARAMETERS[num1][3] );
	
	for( i=num1+1; i<=num2; i++ ){
		ht( A+1, LINK_PARAMETERS[i][0], LINK_PARAMETERS[i][1], LINK_PARAMETERS[i][2], LINK_PARAMETERS[i][3] );
		matrix_multiplication( A, mat[0], A[1] );
		matrix_copy( mat, A[0] );
	}
	for( i=0; i<2; i++ ) matrix_free( A[i] );
}


//�����ϊ��s��̐ς���e�֐߈ʒu�𓱏o���C�֐߈ʒu�Ɋe�֐߂̍��W��\������
void homogeneous_transform( int num, double *pos )
{
	int i, j, k;
	double origin[3][3];
	struct  matrix mat[3];

	for( i=0; i<3; i++ ) matrix_alloc( mat+i, 4, 4 );
	for( i=0; i<4; i++ ) for( j=0; j<4; j++ )       mat[1].data[i][j] = 0.0;
    for( i=0; i<4; i++ )                            mat[1].data[i][i] = 1.0;
	
	for( i=1; i<=num; i++ ){
    	ht( mat, LINK_PARAMETERS[i][0], LINK_PARAMETERS[i][1], LINK_PARAMETERS[i][2], LINK_PARAMETERS[i][3] );
		matrix_multiplication( mat+2, mat[1], mat[0] );
		matrix_copy( mat+1, mat[2] );
	}

	for( i=0; i<3; i++ )    pos[i] = mat[1].data[i][3];
	for( i=0; i<3; i++ ){
		origin[0][i] = pos[i] + mat[1].data[i][0];
		origin[1][i] = pos[i] + mat[1].data[i][1];
		origin[2][i] = pos[i] + mat[1].data[i][2];
	}
	object_frame( pos, origin[0], origin[1], origin[2] );

   	for( i=0; i<3; i++ ) matrix_free( mat[i] );
}


//�}�j�s�����[�^�\���֐�
void display( void )
{
	int     i, k;
	double  object[4][4], x[2][3];
	struct matrix mat;
	
	kik_clear();
	reference_frame();//����W�̕\��
	
	for( k=0; k<3; k++ )    x[0][k] = 0.0;
	x[0][2] =-LINK_PARAMETERS[0][2];

	for( i=1; i<=6; i++ ){//�����ϊ��s��̐ς��瓱�o�����e�֐߈ʒu���Ȃ��Ń}�j�s�����[�^�t���[���̕\��
		homogeneous_transform( i, x[1] );//�����ϊ��֐��̒��Ŋe�֐߈ʒu�̍��W�\�����s���Ă���B
		setcolor( 0x000000 );
		kik_line3D( x[0][0], x[0][1], x[0][2], x[1][0], x[1][1], x[1][2] );
		for( k=0; k<3; k++ )	x[0][k] = x[1][k];
	}

	matrix_alloc( &mat, 4, 4 );
	ht2( 1,7, &mat );//����W����C���܂ł̓����ϊ�
	for( k=0; k<3; k++ )    x[1][k] = mat.data[k][3];
	kik_line3D( x[0][0], x[0][1], x[0][2], x[1][0], x[1][1], x[1][2] );
	robot_hand( mat );//���{�b�g�n���h�����\��
	matrix_free( mat );//�s�񃁃����̉��
}