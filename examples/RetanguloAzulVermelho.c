/*
 * Desafio: verificar o ModelView
 */

#include <GL/glut.h>
#include <GL/glu.h>

void init(void)
{
	/* selecionar cor de fundo (preto) */
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_MODELVIEW); // Projeção 2D

	gluOrtho2D(0.0, 600.0, 0.0, 400.0); // Definindo os limites da Porta de Visão (ViewPort)
}

// Desenha as transformações
void displayRet(void)
{

	// limpa o display
	glClear(GL_COLOR_BUFFER_BIT);

	// Cria um retângulo na cor Azul
	// glColor3f(0.0, 0.0, 1.0);
	// glRecti(50, 100, 200, 150);

	// Cria um retângulo na cor vermelho e translada
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(50.0, 50.0, 0.0);
	glRotatef(-15, 0, 0, 1);
	glTranslatef(-50.0, -50.0, 0.0);
	glRecti(10, 10, 100, 100);

	// Executa os comandos
	glFlush();
}

void close(unsigned char key, int x, int y)
{

	if (key == 'q')
	{
		exit(0);
	}
}

int main(int argc, char *argv[])
{

	/* inicializa o sitema GLUT */
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(600, 400);
	glutCreateWindow("Retângulos");

	// Chama a função "init" e inicia as propriedades do ViewPort
	init();
	/* Callback para mostrar objetos na tela */
	glutDisplayFunc(displayRet);
	/* Callback para para interagir com teclado */
	glutKeyboardFunc(close);
	/* inicia o processamento dos eventos... */
	glutMainLoop();
}
