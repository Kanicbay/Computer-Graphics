#define _USE_MATH_DEFINES
#include <iostream>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>

void init4() {
    glClearColor(0.9, 0.8, 0.7, 1);
    glClearDepth(1);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 4, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
}

void reshape4(GLsizei w, GLsizei h) {
    if (h == 0) {
        h = 1;
    }
    glViewport(0, 0, w, h);
}

void mesa() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glColor3f(0.4, 0.6, 0.7);
    glScalef(1, 0.1, 0.7);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.4, 0.6, 0);
    glTranslatef(0, -1.2, -0.5);
    glRotatef(90, 1, 0, 0);
    glutSolidCylinder(0.15, 1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.4, 0.6, 0);
    glTranslatef(-2.5, -1.2, -0.5);
    glRotatef(90, 1, 0, 0);
    glutSolidCylinder(0.15, 1, 20, 20);
    glPopMatrix();
    
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(600, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ejemplo morph");
    init4();
    glutDisplayFunc(mesa);
    glutReshapeFunc(reshape4);
    glutMainLoop();
    return 0;
}