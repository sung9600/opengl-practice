#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <time.h>
#include <windows.h>

int FlatShaded = 0;
int WireFramed = 0;
float height = 3.0;//initial height
float velocity = 0.98;//9.8m/s^2
int direction = 0; //0: downward, 1:upward

void InitLight() {
	GLfloat mat_diffuse[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_shininess[] = { 15.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 0.8 };
	GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 0.3 };
	GLfloat light_position[] = { -3,6, 3.0, 0.0 };
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glMaterialfv(GL_LIGHT0, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_LIGHT0, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_LIGHT0, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_LIGHT0, GL_SHININESS, mat_shininess);
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':case'Q':case '\033':
		exit(0);
		break;
	case 'w':
		if (WireFramed) {
			WireFramed = 0;
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		else {
			WireFramed = 1;
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		glutPostRedisplay();
		break;
	}
}
void MyTimer(int Value) {
	if (direction == 0) {
		if (height >= 0.0) {
			height -= velocity * 0.01;
			velocity += 0.098;
		}
		else{
			if (velocity >1.0)velocity *= 0.8;
			else velocity = 0;
			direction = 1;
		}
	}
	else {
		if (velocity>0) {
			height += velocity * 0.01;
			velocity -= 0.098;
		}
		else {
			direction = 0;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(10, MyTimer, 1);
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1.0, 0.0, 2.0, 0.0, 0.5, 2.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, height);
	glutSolidSphere(0.5, 30, 30);
	glFlush();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.0, 3.0, -3.0, 3.0, -3.0, 3.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(400, 400);
	glutCreateWindow("opengl");
	glClearColor(0.4, 0.4, 0.4, 0.0);
	InitLight(); 
	glutTimerFunc(40, MyTimer, 1);
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}