#include <GL/glut.h>
#include <GL/glu.h>

#define _USE_MATH_DEFINES
#include <math.h>

void initFlower(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 500.0, 0, 500.0);
}

void flowerFunc(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // limpamos o buffer de cor

    // Desenha o caule
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(248, 250);
    glVertex2i(251, 250);
    glVertex2i(248, 100);
    glVertex2i(251, 100);
    glEnd();

    // Desenha a dita cuja "flor de abril" com 4 pétalas (triângulos) nas direções principais
    int cx = 250, cy = 250;
    float radius = 50.0;
    float colors[4][3] = {
        {1.0, 0.0, 0.0}, // vermelho (cima)
        {0.0, 1.0, 0.0}, // verde (baixo)
        {0.0, 0.0, 1.0}, // azul (esquerda)
        {1.0, 1.0, 0.0}  // amarelo (direita)
    };

    // Desenhamos as pétalas

    // Cima
    glColor3f(colors[0][0], colors[0][1], colors[0][2]);
    glBegin(GL_TRIANGLES);
    glVertex2i(cx, cy);               // centro
    glVertex2i(cx - 20, cy + radius); // esquerda da pétala superior
    glVertex2i(cx + 20, cy + radius); // direita da pétala superior
    glEnd();

    // Baixo
    glColor3f(colors[1][0], colors[1][1], colors[1][2]);
    glBegin(GL_TRIANGLES);
    glVertex2i(cx, cy);
    glVertex2i(cx - 20, cy - radius);
    glVertex2i(cx + 20, cy - radius);
    glEnd();

    // Esquerda
    glColor3f(colors[2][0], colors[2][1], colors[2][2]);
    glBegin(GL_TRIANGLES);
    glVertex2i(cx, cy);
    glVertex2i(cx - radius, cy - 20);
    glVertex2i(cx - radius, cy + 20);
    glEnd();

    // Direita
    glColor3f(colors[3][0], colors[3][1], colors[3][2]);
    glBegin(GL_TRIANGLES);
    glVertex2i(cx, cy);
    glVertex2i(cx + radius, cy - 20);
    glVertex2i(cx + radius, cy + 20);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Flor de Abril");

    initFlower();

    glutDisplayFunc(flowerFunc);

    glutMainLoop();
}