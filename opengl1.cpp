#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

#include <windows.h>


void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd(); 
	glFinish();
}
int main(int argc, char** argv) {
    
	glutInit(&argc, argv);
	glutCreateWindow("OPENGL");
	glutDisplayFunc(display);
	HWND hWndConsole = GetConsoleWindow();
	ShowWindow(hWndConsole, SW_HIDE);
	glutMainLoop();
	return 0;
}