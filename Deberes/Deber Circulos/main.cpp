#include <iostream>
#include <GL/freeglut.h>

//Radios a usar
float radioG = 70, x, y;
float radioP = 45, x2, y2;
float radio = 60, x3, y3;

/*Deber Brian Coyago
  Aplicación de conocimientos para hacer: circulos
  Aplicación de circulos para hacer un ojo
  Objetos usados: lineas y poligonos
*/


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

void ojoConCirculos() {
	//Limpiar el buffer
	glClear(GL_COLOR_BUFFER_BIT);

	//Inicio del contorno
	//Tamaño
	glLineWidth(30);
	
	glBegin(GL_LINES);
		//Colores
		glColor3f(0.0f, 0.0f, 0.0f); // Color Negro
		
		for (float i = 0.0f; i < 180.0f; i += 0.01f) {
			x = radioG * cos(i);
			y = radioG * sin(i);
			glVertex2f(x, y);
		}
	glEnd();
	glutSwapBuffers();

	//Inicio del circulo grande
	glBegin(GL_POLYGON);
		//Colores
		glColor3f(0.0f, 1.0f, 1.0f); // Color Cyan

		for (float i = 0.0f; i < 20.0f; i += 0.01f) {
			x = radioG * cos(i);
			y = radioG * sin(i);
			glVertex2f(x, y);
		}
	glEnd();
	glutSwapBuffers();

	//Inicio del circulo pequeño
	//Preguntar por contorno incompleto
	glBegin(GL_POLYGON);
		//Colores
		glColor3f(0.0f, 0.0f, 0.0f); // Color Negro
		radioP = 45;
		for (float i = 0.0f; i < 20.0f; i += 0.01f) {
			x2 = radioP * cos(i);
			y2 = radioP * sin(i);
			glVertex2f(x2, y2);
		}
	glEnd();
	glutSwapBuffers();

	//Inicio de los circulos pequeños 1
	glBegin(GL_POLYGON);
		//Colores
		glColor3f(1.0f, 1.0f, 1.0f); // Color Blanco
		radioP = 10;
		for (float i = 0.0f; i < 20.0f; i += 0.01f) {
			x2 = radioP * cos(i);
			y2 = radioP * sin(i);
			glVertex2f(x2-14, y2+28);
		}
	glEnd();
	glutSwapBuffers();

	//Inicio de los circulos pequeños 2
	glBegin(GL_POLYGON);
		//Colores
		glColor3f(1.0f, 1.0f, 1.0f); // Color Blanco
		radioP = 5;
		for (float i = 0.0f; i < 20.0f; i += 0.01f) {
			x2 = radioP * cos(i);
			y2 = radioP * sin(i);
			glVertex2f(x2-30, y2+20);
		}
	glEnd();
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	//Tamaño de la ventana
	glutInitWindowSize(640, 640);
	//Posición de la ventana
	glutInitWindowPosition(20, 20);
	//Modo de Display
	glutInitDisplayMode(GLUT_RGB);
	//Crear la ventana
	glutCreateWindow("Ejemplo Circulo 2D");
	glClearColor(1, 1, 1, 0);
	glutDisplayFunc(ojoConCirculos);
	glutReshapeFunc(reshape);
	//Refresco hasta que el usuario cierre
	glutMainLoop();  
	
	return 0;
}