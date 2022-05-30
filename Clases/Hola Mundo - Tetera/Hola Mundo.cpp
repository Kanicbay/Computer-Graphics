#include <GL/freeglut.h>

void reshape(GLint w, GLint h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glColor3d(1, 0, 0);

	glLoadIdentity();

	gluOrtho2D(-1.5, 1.5, -1.5, 1.5);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	//glutWireTeapot(1);
	glutSolidTeapot(1);
	glFlush();
}

int main(int argc, char* argv[]) {

	
	glutInit(&argc, argv);
	
	//Tamaño de la ventana
	glutInitWindowSize(500, 500);
	//Posición de la Ventana
	glutInitWindowPosition(20, 20);
	//Modo de display RGB
	glutInitDisplayMode(GLUT_RGB);

	//Crear la ventana
	glutCreateWindow("Ejemplo de Prueba");
	glClearColor(1, 1, 1, 0); 

	//Definir función display
	glutDisplayFunc(display);

	//Definir función reshape
	glutReshapeFunc(reshape);

	//Mantener en un loop infinito
	glutMainLoop();

	return 0;
}
