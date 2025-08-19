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

    // Planeta vermelho (gira no sentido anti-horário, começa à direita, levemente acima)
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glRotatef((GLfloat)year, 0.0, 1.0, 0.0); // Rotação anti-horária
    glTranslatef(2.0, 0.3, 0.0);             // À direita e levemente acima do sol
    glutWireSphere(0.2, 10, 8);
    glPopMatrix();

    // Planeta azul (gira no sentido horário, começa à esquerda, levemente abaixo)
    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix();
    glRotatef(-(GLfloat)year, 0.0, 1.0, 0.0); // Rotação horária (inverte o sinal)
    glTranslatef(-2.0, -0.3, 0.0);            // À esquerda e levemente abaixo do sol
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

    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // posicao da camera
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
    glutCreateWindow("Translação dos Planetas");

    init();

    glutDisplayFunc(display); // Usada para (re)desenhar a cena
    glutReshapeFunc(reshape); // Usar sempre que existe alteração no tamanho da Janela e ajuste da Viewport
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
