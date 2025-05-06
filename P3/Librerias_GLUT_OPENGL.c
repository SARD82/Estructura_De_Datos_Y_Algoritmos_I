#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0); // Rojo
        glVertex2f(-0.5, -0.5);
        glColor3f(0.0, 1.0, 0.0); // Verde
        glVertex2f(0.5, -0.5);
        glColor3f(0.0, 0.0, 1.0); // Azul
        glVertex2f(0.0, 0.5);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Ejemplo OpenGL con GLUT");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
