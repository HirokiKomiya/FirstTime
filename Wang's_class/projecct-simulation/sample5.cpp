//キーボードに入力したものをコンパイラに表示

#include <stdio.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void disp( void ) {
	glClear(GL_COLOR_BUFFER_BIT);
}

void key(unsigned char key , int x , int y) {
	printf("Key = %c\n" , key);
}

int main(int argc , char ** argv) {
	glutInit(&argc , argv);
	glutInitWindowPosition(100 , 50);
	glutInitWindowSize(400 , 300);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutCreateWindow("Kitty on your lap");
	glutDisplayFunc(disp);
	glutKeyboardFunc(key);

	glutMainLoop();
	return 0;
}