#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <windows.h>

GLint TopLeftx, TopLefty, BottomRightx, BottomRighty;
void display() {
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	glColor3f(0.5, 0.5, 0.5);
	//glutSolidTorus(0.3, 0.7, 5,1000);
	glBegin(GL_POLYGON);
	glVertex3f(TopLeftx / 300.0, (300 - TopLefty) / 300.0, 0.0);
	glVertex3f(TopLeftx / 300.0, (300 - BottomRighty) / 300.0, 0.0);
	glVertex3f(BottomRightx / 300.0, (300 - BottomRighty) / 300.0, 0.0);
	glVertex3f(BottomRightx / 300.0, (300 - TopLefty) / 300.0, 0.0);
	glEnd();
	glFinish();
}
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) { //mouse down시 저장된 지점(default 왼쪽위)에서 클릭지점까지 사각형
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		TopLeftx = X;
		TopLefty = Y;
	}
}

void MyMouseMove(GLint X, GLint Y) {//mouse down 상태로 이동시 클릭위치에서 종료지점까지 사각형
	BottomRightx = X;
	BottomRighty = Y;
	glutPostRedisplay();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
	switch (KeyPressed) {
		case 'Q':
			exit(0);
			break;
		
		case 'q':
			exit(0);
			break;
		case 27://esc
			exit(0);
			break;
	}//q나 esc누르면 싹 종료
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(display);
	glutKeyboardFunc(MyKeyboard);
	glutMouseFunc(MyMouseClick);
	glutMotionFunc(MyMouseMove);
	HWND hWndConsole = GetConsoleWindow();
	ShowWindow(hWndConsole, SW_HIDE);
	glutMainLoop();
	return 0;
}