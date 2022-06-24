#include <iostream>
#include <GL/freeglut.h>


static GLfloat angulo = 0;
static GLfloat angulo2 = 0;
static GLfloat angulo3 = 0;
static int tiempo = 5;

void init2() {
    glClearColor(0, 0, 0, 0);
    glClearDepth(1);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 20);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}


void reshape2(GLsizei w, GLsizei h) {
    if (h == 0) {
        h = 1;
    }
    glViewport(0, 0, w, h);
}

void cubo() {
    glBegin(GL_QUADS);

    //Top
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(1, 1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);

    //Bottom
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);

    //Delate
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);

    //Atras
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1, -1, -1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);

    //Izq
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);

    //Der
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    glEnd();
}


void timer(int valor) {
    glutPostRedisplay();
    glutTimerFunc(tiempo, timer,0);
}

void display2() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //Cubo 1
    glPushMatrix();
    glRotatef(angulo,0, 1, 1);
    cubo();
    glPopMatrix();

    //Cubo 2
    glPushMatrix();
    glTranslatef(-4,1,0);
    glRotatef(angulo2, 1, 1, 0);
    glScalef(0.5, 0.5, 0.5);
    cubo();
    glPopMatrix();

    //Cubo 3
    glPushMatrix();
    glTranslatef(4, -1, 0);
    glRotatef(angulo3, 1, 1, 1);
    glScalef(0.8, 0.8, 0.8);
    cubo();
    glPopMatrix();
    

    angulo += 0.15;
    angulo2 += 0.2;
    angulo3 += 0.3;
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(600, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ejemplo animacion");
    init2();
    glutDisplayFunc(display2);
    glutReshapeFunc(reshape2);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}

