#include <GL/glut.h>
#include <GL/glu.h>

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

    // os ângulos são: cima (90), direita (0), baixo (270), esquerda (180)
    float angles[4] = {90.0, 0.0, 270.0, 180.0};

    for (int i = 0; i < 4; i++)
    {
        float angle = angles[i] * 3.1415926f / 180.0f;
        float left = (angles[i] - 30.0f) * 3.1415926f / 180.0f;
        float right = (angles[i] + 30.0f) * 3.1415926f / 180.0f;

        // Desenha uma das pétalas (triângulo) com a cor, posição e ângulos calculados
        glColor3f(colors[i][0], colors[i][1], colors[i][2]);
        glBegin(GL_TRIANGLES);
        glVertex2i(cx, cy);
        glVertex2i(cx + (int)(radius * cos(left)), cy + (int)(radius * sin(left)));
        glVertex2i(cx + (int)(radius * cos(right)), cy + (int)(radius * sin(right)));
        glEnd();
    }

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