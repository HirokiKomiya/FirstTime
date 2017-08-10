#include<GL/glut.h>

double vertices[][3]={//�l�p�`
	{0.0, 0.5, 0.0},
	{0.0, 0.0, 0.0},
	{0.5, 0.0, 0.0},
	{0.5, 0.5, 0.0}
};

double tx = 0.0;
double ty = 0.0;
double tz = 0.0;
double rx = 0.0;
double ry = 0.0;
double rz = 0.0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//�������烂�f�����O�ϊ�
	glLoadIdentity(); //����ϊ��E���f�����O�ϊ��̕ϊ��s���P�ʍs��ŏ�����
	glTranslated(tx, ty, tz); //���s�ړ�
	glRotated(rx, 1.0, 0.0, 0.0); //X����]
	glRotated(ry, 0.0, 1.0, 0.0); //Y����]
	glRotated(rz, 0.0, 0.0, 1.0); //Z����]

	//�������烂�f�����O���W�n
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP); //�v���~�e�B�u�̎w���2D�̎��Ɠ���
	for(int i=0; i < 4; i++)
		glVertex3dv(vertices[i]); //2d�ł͂Ȃ�3d
	glEnd();

	glFlush();
}

void resize(int w, int h) 
{
	glViewport(0, 0, w, h); //�E�C���h�E�S�̂ɕ\��
	glMatrixMode(GL_PROJECTION); //���e�ϊ����[�h��
	glLoadIdentity(); //���e�ϊ��̕ϊ��s���P�ʍs��ŏ�����
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0); //�e��-1.0�`1.0�ň͂܂�闧���͈̂̔͂���s���e

        glMatrixMode(GL_MODELVIEW); //����ϊ��E���f�����O�ϊ����[�h��
	glLoadIdentity(); //����ϊ��E���f�����O�ϊ��̕ϊ��s���P�ʍs��ŏ�����
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case '4':
			tx -= 0.01;
		break;
		case '6':
			tx += 0.01;
		break;
		case '2':
			ty -= 0.01;
		break;
		case '8':
			ty += 0.01;
		break;
		case '9':
			tz -= 0.01;
		break;
		case '1':
			tz += 0.01;
		break;
		case 'x':
			rx += 2.0;
		break;
		case 'y':
			ry += 2.0;
		break;
		case 'z':
			rz += 2.0;
		break;
		default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitWindowPosition(100, 100); //�E�C���h�E��\�������ʏ�̍���̈ʒu
	glutInitWindowSize(320, 240); //�E�C���h�E�̃T�C�Y

	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(resize); //�֐�resize���R�[���o�b�N�ɐݒ�
	glutKeyboardFunc(keyboard);
   	glClearColor(0.0, 0.0, 0.0, 0.0);
        glutMainLoop();
	return 0;
}