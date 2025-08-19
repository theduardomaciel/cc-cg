//
//  main.c
//  Mouse Function
//
//  Created by Marcelo Costa  on 27/11/12.
//  Copyright (c) 2012 UFAL. All rights reserved.
//

#include <GL/glut.h>
#include <GL/glu.h>

GLsizei winWidth = 400, winHeight = 300;

// Procedimentos de inicialização
void init(void)
{

	glClearColor(0.0, 0.0, 1.0, 1.0); // Cor da Janela em Azul

	glMatrixMode(GL_PROJECTION); // Aplica operações de matriz subsequentes à pilha da matriz de projeção

	glOrtho(0.0, 200.0, 0.0, 150.0, -1.0, .0); // Definindo os limites da projeção
}

void displayFcn(void)
{

	glClear(GL_COLOR_BUFFER_BIT); // Limpa a ViewPort

	glColor3f(1.0, 0.0, 0.0); // Pontos em Vermelho
	glPointSize(10.0);		  // Tamanho do Ponto

	glFlush(); // Executa os comandos OpenGL
}

void plotPoint(GLint x, GLint y)
{

	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void mousePtPlot(GLint button, GLint action,
				 GLint xMouse, GLint yMouse)
{
	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)
	{
		int x1 = xMouse;
		int y1 = winHeight - yMouse;
		plotPoint(x1, y1);

		// ATENÇÃO: Xo e Yo no canto superior esquerdo;
		// cout<<"x1 da função" <<x1<<endl;
		// cout<<"y1 da função" <<y1<<endl;
		winWidth = winWidth * 1000;
	}
	glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // atualiza os objetos da janela
	glOrtho(0.0, (GLdouble)newWidth, 0.0, (GLdouble)newHeight, -1.0, .0);

	winWidth = newWidth;
	winHeight = newHeight;

	glFlush();
}

int main(int argc, char **argv)
{

	// Inicializa a GLUT
	glutInit(&argc, argv);

	// Janela com Buffer simples e em RGB
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Pontos usando Mouse");

	init(); // Chama os procedimentos de inicialização

	glutDisplayFunc(displayFcn);
	glutReshapeFunc(winReshapeFcn);
	glutMouseFunc(mousePtPlot);

	glutMainLoop();

	return 0;
}
