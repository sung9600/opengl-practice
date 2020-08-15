#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <windows.h>


void display() {
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//glViewport(0, 0, 500, 500);
	glColor3f(0.5f, 0.5f, 0.5f);
	//glutSolidTorus(0.3, 0.7, 5,1000);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();
	glFinish();
}
void MyReshape(int width, int height) {//이함수로 가시부피 arg에 비례해서 조절 -> 창크기 변해도 비율유지
	glViewport(0, 0, width, height);
	GLfloat WidthFactor = (GLfloat)width / (GLfloat)300;
	GLfloat HeightFactor = (GLfloat)height / (GLfloat)300;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPENGL");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);//처음 열때, 위치 옮길때, 크기바뀔때 자동으로 콜백
	HWND hWndConsole = GetConsoleWindow();
	ShowWindow(hWndConsole, SW_HIDE);
	glutMainLoop();
	return 0;
}