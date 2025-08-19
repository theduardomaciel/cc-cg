#include <GL/glut.h>
#include <GL/glu.h>

static int year = 0, day = 0;

// Inicializa parâmetros de rendering
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST); // Ativa o teste de profundidade
}

// Função callback chamada para fazer o desenho
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Habilita blending e define opacidade total (opaco)
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);                // Mantém o sol na vertical (eixo X)
    GLfloat sunColor[] = {1.0f, 1.0f, 0.0f, 1.0f}; // Amarelo opaco (alpha = 1)
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, sunColor);
    glColor3f(1.0f, 1.0f, 0.0f);  // Define a cor do sol como amarelo
    glutSolidSphere(1.0, 20, 16); /* Desenha o sol */
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0); // Muda a cor dos planetas para branco

    glPushMatrix();
    glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
    glTranslatef(2.0, 0.0, 0.0); // Translada a partir do novo sistema de coordenadas resultante da rotação
    glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
    glutWireSphere(0.2, 10, 8); /* desenha um planeta */
    glPopMatrix();

    glDisable(GL_BLEND);

    glutSwapBuffers(); // substitui o Flush quando usamos o GLUT_DOUBLE
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
    case 'd':
        day = (day + 10) % 360; //% valor do resto
        glutPostRedisplay();    // Redesenha a cena com novas coordenadas, é executado no glutMainLoop;
        break;
    case 'D':
        day = (day - 10) % 360;
        glutPostRedisplay();
        break;
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
    glutCreateWindow("Rotacao de Planetas");

    init();
    glutDisplayFunc(display); // Usada para (re)desenhar a cena
    glutReshapeFunc(reshape); // Usar sempre que existe alteração no tamanho da Janela e ajuste da Viewport
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
