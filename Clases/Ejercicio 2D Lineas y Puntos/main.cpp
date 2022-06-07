#include <iostream>
#include <GL/freeglut.h>

void reshape(GLint w, GLint h) {
	//Cambiar el tamaño de la ventana
	//Configura el viewport desde donde inicia y el tamaño
	glViewport(0, 0, w, h);
	//Agregar la matriz de proyección
	glMatrixMode(GL_PROJECTION);
	//Encerar la matriz
	glLoadIdentity();
	//Agregar una matriz ortogonal
	gluOrtho2D(-100, 100, -100, 100);
}

void puntosDisp() {
	//Quitar el color por defecto
	glClear(GL_COLOR_BUFFER_BIT);
	//Tamaño de los puntos
	glPointSize(10);
	glBegin(GL_POINTS);
		glColor3f(1,1,0);
		glVertex2f(2.5,5.7);
		glVertex3f(50, 40, 5);
	glEnd();
	glutSwapBuffers();
}

void lineasDisp() {
	glClearColor(0.5,0.5,0.5,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(1);
	glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex2i(50, -50);
		glVertex2i(-45, 50);
	glEnd();
	glutSwapBuffers();

	glLineWidth(10);
	glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex2i(-50, -50);
		glVertex2i(45, 50);
	glEnd();
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	//Tamaño de la ventana
	glutInitWindowSize(640, 480);
	//Posición de la ventana
	glutInitWindowPosition(100, 100);
	//Crear la ventana
	glutCreateWindow("Ejemplo 2D");
	glutDisplayFunc(lineasDisp);
	glutReshapeFunc(reshape);
	//Refresco hasta que el usuario cierre
	glutMainLoop();  
	
	return 0;
}