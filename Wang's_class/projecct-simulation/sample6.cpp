#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void disp( void ) {
	static GLboolean isUp = GL_TRUE;
	static GLfloat top = -0.9;

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
		glVertex3f(-0.9 , -0.9,0);
		glVertex3f(0 , top,1);
		glVertex3f(0.9 , -0.9,1);
	glEnd();


	glFlush();
}

void Idle() {
	glutPostRedisplay();
}

int main(int argc , char ** argv) {
	glutInit(&argc , argv);
	glutInitWindowPosition(100 , 50);
	glutInitWindowSize(400 , 300);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutCreateWindow("Kitty on your lap");
	glutDisplayFunc(disp);
	glutIdleFunc(Idle);

	glutMainLoop();
	return 0;
}