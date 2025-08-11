#include <GL/glut.h>
#include <GL/glu.h>

#define _USE_MATH_DEFINES
#include <math.h>

char rotationKey = 'r';     // Tecla para rotacionar a flor
char antiRotationKey = 'e'; // Tecla para anti-rotacionar

float flowerAngle = 0.0f;  // Ângulo de rotação da flor
float flowerVel = 0.0f;    // Velocidade angular
float flowerAcc = 0.0f;    // Aceleração angular
float flowerVelMax = 5.0f; // Velocidade máxima

void initFlower(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 500.0, 0, 500.0);
}

void flowerFunc(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // limpamos o buffer de cor

    // Desenha o caule como um retângulo simples
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(248, 250);
    glVertex2i(251, 250);
    glVertex2i(251, 100);
    glVertex2i(248, 100);
    glEnd();

    // Rotaciona a flor
    glPushMatrix();         // Salva a matriz atual
    int cx = 250, cy = 250; // Centro da flor

    // Antes de rotacionar, movemos para a origem
    glTranslatef(cx, cy, 0);

    // Em seguida, rotacionamos a flor
    glRotatef(flowerAngle, 0, 0, 1);

    // E finalmente, movemos de volta para a posição original
    glTranslatef(-cx, -cy, 0);

    float radius = 50.0;
    float colors[4][3] = {
        {1.0, 0.0, 0.0}, // vermelho (cima)
        {0.0, 1.0, 0.0}, // verde (baixo)
        {0.0, 0.0, 1.0}, // azul (esquerda)
        {1.0, 1.0, 0.0}  // amarelo (direita)
    };

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

    glPopMatrix();
    glFlush();
}

// Função de callback para teclado
void keyboardFunc(unsigned char key, int x, int y)
{
    // Escolhemos uma tecla para rotacionar (considerando as variantes minúscula e maiúscula)
    if (key == rotationKey || key == rotationKey - 32)
    {
        // Ao pressionar a tecla, aplica aceleração para iniciar rotação
        flowerAcc = -0.05f; // valor negativo para sentido anti-horário
    }
    // Para parar suavemente ao soltar a tecla
    if (key == 's' || key == 'S')
    {
        flowerAcc = 0.05f; // valor positivo para desacelerar
    }
}

// Timer para atualizar animação
void timerFunc(int value)
{
    // Atualizamos a velocidade com base na aceleração
    flowerVel += flowerAcc;

    // Limitamos a velocidade máxima (pra não explodir a flor)
    if (flowerVel > flowerVelMax)
        flowerVel = flowerVelMax;
    if (flowerVel < -flowerVelMax)
        flowerVel = -flowerVelMax;

    // Aplica "atrito" para desacelerar suavemente
    if (flowerAcc == 0.0f)
    {
        flowerVel *= 0.98f; // fator de amortecimento

        // Se a velocidade for muito baixa, paramos a flor
        if (fabs(flowerVel) < 0.01f)
        {
            flowerVel = 0.0f;
        }
    }

    // Atualizamos o ângulo da flor com base na velocidade
    flowerAngle += flowerVel;

    // Garantimos que o ângulo esteja sempre no intervalo [0, 360)
    if (flowerAngle >= 360.0f)
    {
        flowerAngle -= 360.0f;
    }

    // Garantimos que o ângulo esteja sempre positivo
    if (flowerAngle < 0.0f)
    {
        flowerAngle += 360.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, timerFunc, 0); // chama novamente em ~16ms (60fps)
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
    glutKeyboardFunc(keyboardFunc);  // Adiciona o callback do teclado
    glutTimerFunc(16, timerFunc, 0); // inicia timer para animação suave
    glutMainLoop();
}