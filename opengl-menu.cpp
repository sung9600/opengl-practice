#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <windows.h>

GLboolean IsSphere = true;
GLboolean IsSmall = true;

void display() {
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//glViewport(0, 0, 300, 300);
	glColor3f(0.5, 0, 0.5);
	if ((IsSphere) && (IsSmall)) {
		glutWireSphere(0.2, 15, 15);
	}
	else if ((IsSphere) && (!IsSmall)) {
		glutWireSphere(0.4, 15, 15);
	}
	else if ((!IsSphere) && (IsSmall)) {
		glutWireTorus(0.1, 0.3, 40, 20);
	}
	else glutWireTorus(0.2, 0.5, 40, 20);
	glFlush();
}

void MyMainMenu(int entryId) {//마우스우클릭 메뉴(모양)
	if (entryId == 1)IsSphere = true;
	else if (entryId == 2)IsSphere = false;
	else exit(0);
	glutPostRedisplay();
}

void MySubmenu(int entryId) {//마우스우클릭 메뉴(크기)
	if (entryId == 1)IsSmall = true;
	else if (entryId == 2)IsSmall = false;
	glutPostRedisplay();
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
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	GLint MySubMenuId = glutCreateMenu(MySubmenu);//가장 나중 메뉴가 처음 등록됨
	glutAddMenuEntry("Small", 1);
	glutAddMenuEntry("Big", 2);
	GLint MyMainMenuId = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Sphere", 1);
	glutAddMenuEntry("Torus", 2);
	glutAddSubMenu("Change Size", MySubMenuId);
	glutAddMenuEntry("Exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(display);
	HWND hWndConsole = GetConsoleWindow();
	ShowWindow(hWndConsole, SW_HIDE);
	glutMainLoop();
	return 0;
}