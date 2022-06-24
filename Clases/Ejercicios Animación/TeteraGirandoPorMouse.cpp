#include <iostream>
#include <GL/freeglut.h>

static bool isKey = false;
static float posx = 0;
GLfloat spin = 0;
static bool ismouse = false;

void init() {
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	if (isKey) {
		glTranslatef(posx,0,0);
	}
	if (ismouse) {
		glRotatef(spin,0,0,1);
	}
	glutWireTeacup(1);
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void reshape(GLint w, GLint h) {
	if (h == 0) {
		h = 1;
	}
	glViewport(0, 0, w, h);
}

void movIzq() {
	if (isKey) {
		posx -= 0.01;
	}
	if (ismouse) {
		spin -= 0.2;
		if (spin < 360) {
			spin += 360;
		}
	}
	glutPostRedisplay();
}

void movDer() {
	if (isKey) {
		posx += 0.01;
	}
	glutPostRedisplay();
}

void keyboard(int key, int, int) {
	switch (key) {
	case GLUT_KEY_LEFT:
		isKey = true;
		glutIdleFunc(movIzq);
		break;
	case GLUT_KEY_RIGHT:
		isKey = true;
		glutIdleFunc(movDer);
		break;
	default:
		break;
	}
}

void keyboardUp(int key, int, int) {
	switch (key) {
	case GLUT_KEY_LEFT:
		isKey = false;
		glutIdleFunc(NULL);
		break;
	case GLUT_KEY_RIGHT:
		isKey = false;
		glutIdleFunc(NULL);
		break;
	default:
		break;
	}
}

void mouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			ismouse = true;
			glutIdleFunc(movIzq);
		}
		else if (state == GLUT_UP) {
			ismouse = false;
			glutIdleFunc(NULL);
		}
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(600, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Ejemplo Animación");

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard);
	glutSpecialUpFunc(keyboardUp);
	glutMouseFunc(mouse);

	glutMainLoop();
	return 0;
}