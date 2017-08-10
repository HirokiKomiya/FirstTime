/**********************************************************

�O���t�B�b�N�̎g�����D

kik_init( hwnd );	�O���t�B�b�N�̏������Dhwnd��CreateWindow�֐��̖߂�l

kik_line3D( x, y, z, ex, ey, ez ); ���Ƃ́C�������������D

setcolor( 0xFF );	����ŐF���ς�����DF��16�i���D0xFF�͐ԁD

**********************************************************/
#define PAI atan2(0.0,-1.0) // 3.1415926535897932385
#define deg(r) ((r)/PAI*180.0)
#define rad(d) ((d)/180.0*PAI)
#define GSIZE 200.0
#define MoveTo(hdc, x, y) (MoveToEx((hdc), (x), (y), NULL))

HPEN 	KPEN;
HDC	KHDC;
HGDIOBJ KHDL;

void	kik_init( HWND hwnd )
{
	PAINTSTRUCT ps;

	KHDC = BeginPaint(hwnd, &ps);
	KPEN = CreatePen(PS_SOLID,1,0x000000);
	KHDL = SelectObject(KHDC, KPEN);
}

/**********************************************************
	�e�L�X�g�t�B�[���h����̓ǂݏo���֐�
	����	�c	�E�C���h�E�n���h���i���ʂh�c�݂����ȃ��m�j
	�߂�l	�c	double�^����
	����	�c	������̓ǂݏo��
				������𕂓������_�ɕϊ�
 **********************************************************/
double getTField(HWND label)
{
	double ret;
	TCHAR	kstr[255];

	GetWindowText( label, kstr, 255 );
	ret = strtod( kstr, NULL);

	return ret;
}

/**********************************************************
	�e�L�X�g�t�B�[���h�쐬�p�֐�
	����	�c	�����l�p�萔
				�����ʒu...������(0,0)
	�߂�l	�c	�E�C���h�E�n���h���i���ʂh�c�݂����ȃ��m�j
	����	�c	CreateWindow()�ɂ��e�L�X�g�t�B�[���h�̍쐬
 **********************************************************/
HWND createTField( HWND hwnd, TCHAR *label, int x, int y){
	HWND ret;

	ret = CreateWindow(	TEXT("EDIT") , TEXT(label) ,
						WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT ,
						x , y , 40 , 20 , hwnd , (HMENU)1 ,
						NULL , NULL
					);

	return ret;
}

void    kik_clear( void )
{
        BitBlt(KHDC, 40, 0, 640, 480, NULL, 0, 0, WHITENESS);   
}

void    rotate_z( double roll, double *x )
{
        double  xx, yy;

        xx = cos(roll) * x[0] - sin(roll) * x[1];
        yy = sin(roll) * x[0] + cos(roll) * x[1];
//        zz = x[2];

        x[0] = xx;        x[1] = yy;
}

void    rotate_y( double pitch, double *x )
{
        double  xx, zz;

        xx = cos(pitch) * x[0] + sin(pitch) * x[2];
//        yy = x[1];
        zz =-sin(pitch) * x[0] + cos(pitch) * x[2];

        x[0] = xx;        x[2] = zz;
}

void    rotate_x( double yaw, double *x )
{
        double  yy, zz;

//        xx = x[0];
        yy = cos(yaw) * x[1] - sin(yaw) * x[2];
        zz = sin(yaw) * x[1] + cos(yaw) * x[2];

        x[1] = yy;        x[2] = zz;
}

void	setcolor( COLORREF a )	/*** a �͂P�U�i����0xFF�Ƃ���ΐԂɂȂ�@***/
{
	DeleteObject( KHDL );
	KPEN = CreatePen(PS_SOLID,1, a );
	KHDL = SelectObject(KHDC, KPEN);
}

void    kik_line3D( double sx, double sy, double sz, double ex, double ey, double ez )
{
        double  xx[2][3];

        xx[0][0] = sx; xx[0][1] = sy; xx[0][2] = sz;
        rotate_z( rad(-120.0), xx[0] );
        rotate_x( rad(30.0), xx[0] );
        xx[1][0] = ex; xx[1][1] = ey; xx[1][2] = ez;
        rotate_z( rad(-120.0), xx[1] );
        rotate_x( rad(30.0), xx[1] );

	/*	xx[0][0] = sx; xx[0][1] = sy; xx[0][2] = sz;
        rotate_z( rad(0.0), xx[0] );
        rotate_x( rad(90.0), xx[0] );
        xx[1][0] = ex; xx[1][1] = ey; xx[1][2] = ez;
        rotate_z( rad(0.0), xx[1] );
        rotate_x( rad(90.0), xx[1] );
     */
        MoveTo(KHDC, (int)(GSIZE*xx[0][0]+GSIZE), (int)(-GSIZE*xx[0][2]+GSIZE) ); LineTo(KHDC, (int)(GSIZE*xx[1][0]+GSIZE), (int)(-GSIZE*xx[1][2]+GSIZE) );

}





