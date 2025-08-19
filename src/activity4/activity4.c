#include <GL/glut.h>
#include <GL/glu.h>

static int year = 0; // Variável para controlar a rotação anual dos planetas

// Inicializa parâmetros de rendering
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST); // Ativa a sobreposição de profundidade
}

// Função callback chamada para fazer o desenho
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Habilita blending e define opacidade total (opaco)
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Desenha o sol
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);                // Mantém o sol na vertical (eixo X)
    GLfloat sunColor[] = {1.0f, 1.0f, 0.0f, 1.0f}; // Amarelo opaco (alpha = 1)
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, sunColor);
    glColor3f(1.0f, 1.0f, 0.0f);  // Define a cor do sol como amarelo
    glutSolidSphere(1.0, 20, 16); // Desenha o sol como uma esfera sólida
    glPopMatrix();

    // Planeta vermelho (gira 90º no eixo X, começa à direita, levemente acima)
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);          // Rotação padrão de 90º no eixo X
    glRotatef((GLfloat)year, 0.0, 0.0, 1.0); // Rotação anual no eixo Z (após girar 90º em X)
    glTranslatef(2.0, 0.0, 0.3);             // À direita e levemente acima do sol (ajustado para novo plano)
    glutWireSphere(0.2, 10, 8);

    // Lua 1: gira ao redor do planeta vermelho no eixo X (após rotação)
    glPushMatrix();
    glRotatef((GLfloat)(year * 3), 0.0, 0.0, 1.0); // Rotação mais rápida no eixo X (aqui Z, após rotação de 90º)
    glTranslatef(0.5, 0.0, 0.0);                   // Distância da lua ao planeta
    glColor3f(0.7, 0.7, 0.7);                      // Cor cinza
    glutWireSphere(0.07, 8, 6);
    glPopMatrix();

    // Lua 2: gira ao redor do planeta vermelho no eixo XY
    glPushMatrix();
    glRotatef((GLfloat)(year * 2), 0.0, 1.0, 1.0); // Rotação no plano XY (aqui YZ, após rotação de 90º)
    glTranslatef(0.0, 0.0, 0.7);                   // Distância da lua ao planeta
    glColor3f(0.5, 0.5, 0.9);                      // Cor azulada
    glutWireSphere(0.07, 8, 6);
    glPopMatrix();

    glPopMatrix();

    // Planeta azul (gira 90º no eixo X, começa à esquerda, levemente abaixo)
    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);           // Rotação padrão de 90º no eixo X
    glRotatef(-(GLfloat)year, 0.0, 0.0, 1.0); // Rotação anual no eixo Z (sentido horário)
    glTranslatef(-2.0, 0.0, -0.3);            // À esquerda e levemente abaixo do sol (ajustado para novo plano)
    glutWireSphere(0.2, 10, 8);
    glPopMatrix();

    glDisable(GL_BLEND);

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0); // Define a perspectiva da câmera
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);   // E aqui a posição da câmera
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'y':
        year = (year + 5) % 360;
        glutPostRedisplay();
        break;
    case 'Y':
        year = (year - 5) % 360;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Translacao dos Planetas");

    init();

    glutDisplayFunc(display); // Usada para (re)desenhar a cena
    glutReshapeFunc(reshape); // Usar sempre que existe alteração no tamanho da Janela e ajuste da Viewport
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
