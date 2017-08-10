#include "matrix.h"

#define J1_ULMT  150 //第1関節角度リミット 正方向
#define J1_LLMT -150 //第1関節角度リミット 負方向
#define J2_ULMT  120 //第2関節角度リミット 正方向
#define J2_LLMT  -60 //第2関節角度リミット 負方向
#define J3_ULMT  120 //第3関節角度リミット 正方向
#define J3_LLMT -110 //第3関節角度リミット 負方向
#define J4_ULMT   90 //第4関節角度リミット 正方向
#define J4_LLMT  -90 //第4関節角度リミット 負方向
#define J5_ULMT   90 //第5関節角度リミット 正方向
#define J5_LLMT  -90 //第5関節角度リミット 負方向

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


HANDLE hCommW;     //シリアルポートのハンドル 
DWORD writesize1,readsize;  //ポートへ書き込んだバイト数,読み込んだバイト数 


// ボーレート設定リスト Host-PC - 補助基板 では9600を使用している
typedef enum {       
    br2400  = 2400, 
    br4800  = 4800,
    br9600  = 9600,  //今回使用しているボーレート
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


//リンクパラメータの初期化
//目標関節角度などが代入される
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

//同次変換行列の生成
void ht( struct matrix *mat, double a, double alpha, double d, double theta )
{
	mat->data[0][0] = cos(theta);            mat->data[0][1] =-sin(theta);            mat->data[0][2] = 0.0;           mat->data[0][3] = a;
	mat->data[1][0] = cos(alpha)*sin(theta); mat->data[1][1] = cos(alpha)*cos(theta); mat->data[1][2] =-sin(alpha);    mat->data[1][3] =-sin(alpha)*d;
	mat->data[2][0] = sin(alpha)*sin(theta); mat->data[2][1] = sin(alpha)*cos(theta); mat->data[2][2] = cos(alpha);    mat->data[2][3] = cos(alpha)*d;
	mat->data[3][0] = 0.0;                   mat->data[3][1] = 0.0;                   mat->data[3][2] = 0.0;           mat->data[3][3] = 1.0;
}

//基準座標の表示
void reference_frame( void )
{
	setcolor( 0xFF );   	kik_line3D( 0.0, 0.0, 0.0, 2.0*AXIS_L, 0.0, 0.0 );
	setcolor( 0xFF00 ); 	kik_line3D( 0.0, 0.0, 0.0, 0.0, 2.0*AXIS_L, 0.0 );
	setcolor( 0xFF0000 ); 	kik_line3D( 0.0, 0.0, 0.0, 0.0, 0.0, 2.0*AXIS_L );
}


//各関節の位置に座標軸を表示する関数
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
//ハンド部分の座標生成＆表示関数
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

//指定した番号の区間で同次変換の積を行う関数．ロボットハンド位置表示時に使用
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


//同次変換行列の積から各関節位置を導出し，関節位置に各関節の座標を表示する
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


//マニピュレータ表示関数
void display( void )
{
	int     i, k;
	double  object[4][4], x[2][3];
	struct matrix mat;
	
	kik_clear();
	reference_frame();//基準座標の表示
	
	for( k=0; k<3; k++ )    x[0][k] = 0.0;
	x[0][2] =-LINK_PARAMETERS[0][2];

	for( i=1; i<=6; i++ ){//同次変換行列の積から導出した各関節位置をつないでマニピュレータフレームの表示
		homogeneous_transform( i, x[1] );//同次変換関数の中で各関節位置の座標表示を行っている。
		setcolor( 0x000000 );
		kik_line3D( x[0][0], x[0][1], x[0][2], x[1][0], x[1][1], x[1][2] );
		for( k=0; k<3; k++ )	x[0][k] = x[1][k];
	}

	matrix_alloc( &mat, 4, 4 );
	ht2( 1,7, &mat );//基準座標から，手先までの同次変換
	for( k=0; k<3; k++ )    x[1][k] = mat.data[k][3];
	kik_line3D( x[0][0], x[0][1], x[0][2], x[1][0], x[1][1], x[1][2] );
	robot_hand( mat );//ロボットハンド部分表示
	matrix_free( mat );//行列メモリの解放
}