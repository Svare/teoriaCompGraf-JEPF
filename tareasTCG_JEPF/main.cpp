/*
	Pacheco Franco Jesús Enrique
*/

#include <GL\glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isE = true;

///////////////////////////////

void renderOcta(float cx, float cy, float radius, float z) {

	float side = radius * 0.70710678118;

	printf("Valor radio :  %f , calor side: %f \n\n", radius, side);

	glBegin(GL_LINE_LOOP);

	glVertex3f(cx, cy + radius, z);
	glVertex3f(cx + side, cy + side, z);
	glVertex3f(cx + radius, cy, z);
	glVertex3f(cx + side, cy - side, z);
	glVertex3f(cx, cy - radius, z);
	glVertex3f(cx - side, cy - side, z);
	glVertex3f(cx - radius, cy, z);
	glVertex3f(cx - side, cy + side, z);

	glEnd();


}



void renderX(float cx, float cy, float z, float length) {

	float p = length * .75;



	float w = length * .20;


	glColor3f(0.6, 0.9, 0.2);
	glBegin(GL_POLYGON);

	glVertex3f(cx, cy, z);
	glVertex3f(cx + w, cy + p, z);
	glVertex3f(cx, cy + length, z);
	glVertex3f(cx - w, cy + p, z);
	glEnd();


	glBegin(GL_POLYGON);

	glVertex3f(cx, cy, z);
	glVertex3f(cx + p, cy + w, z);
	glVertex3f(cx + length, cy, z);
	glVertex3f(cx + p, cy - w, z);
	glEnd();



	glBegin(GL_POLYGON);

	glVertex3f(cx, cy, z);
	glVertex3f(cx + w, cy - p, z);
	glVertex3f(cx, cy - length, z);
	glVertex3f(cx - w, cy - p, z);


	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(cx, cy, z);
	glVertex3f(cx - p, cy + w, z);
	glVertex3f(cx - length, cy, z);
	glVertex3f(cx - p, cy - w, z);
	glEnd();


}

///////////////////////////////

// Con esta funcion se dibuja cada uno de los pedazos de la cruz

void renderCrossSnippet(GLfloat *v0, GLfloat *v1, GLfloat *v2, GLfloat *v3, GLfloat *v4) {
	glBegin(GL_TRIANGLES);
		glVertex3fv(v0);
		glVertex3fv(v3);
		glVertex3fv(v1);

		glVertex3fv(v3);
		glVertex3fv(v4);
		glVertex3fv(v1);

		glVertex3fv(v0);
		glVertex3fv(v2);
		glVertex3fv(v3);

		glVertex3fv(v3);
		glVertex3fv(v2);
		glVertex3fv(v4);
	glEnd();
}

// Se encarga de dibujar la cruz completa usando la funcion renderCrossSnippet

void renderTriangleCross() {
	GLfloat vertexes[17][3] = { {0.0f,0.0f,-3.0f},
								{-1.0f,5.0f,-3.0f},
								{1.0f,5.0f,-3.0f},
								{0.0f,5.0f,-3.0f},
								{0.0f,6.0f,-3.0f},
								{-1.0f,-5.0f,-3.0f},
								{1.0f,-5.0f,-3.0f},
								{0.0f,-5.0f,-3.0f},
								{0.0f,-6.0f,-3.0f},
								{-5.0f,-1.0f,-3.0},
								{-5.0f,1.0f,-3.0f},
								{-5.0f,0.0f,-3.0f},
								{-6.0f,0.0f,-3.0f},
								{5.0f,-1.0f,-3.0f},
								{5.0f,1.0f,-3.0f},
								{5.0f,0.0f,-3.0f},
								{6.0f,0.0f,-3.0f} };

	glColor3f(1.0, 1.0, 0.0);
	renderCrossSnippet(vertexes[0], vertexes[9], vertexes[10], vertexes[11], vertexes[12]); // LEFT
	glColor3f(0.0, 1.0, 0.0);
	renderCrossSnippet(vertexes[0], vertexes[1], vertexes[2], vertexes[3], vertexes[4]); // TOP
	glColor3f(0.0, 0.0, 1.0);
	renderCrossSnippet(vertexes[0], vertexes[14], vertexes[13], vertexes[15], vertexes[16]); // RIGHT
	glColor3f(0.0, 1.0, 1.0);
	renderCrossSnippet(vertexes[0], vertexes[6], vertexes[5], vertexes[7], vertexes[8]); // BOTTOM

}

void renderOctagone() {
	GLfloat x, y;
	x = 3.535533906; // 5 * cos(45)
	y = 3.535533906; // 5 * sin(45)

	glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 1.0, 0.3);
		glVertex3f(5.0, 0.0, -3.0);
		glVertex3f(x, y, -3.0);
		glVertex3f(0.0, 5.0, -3.0);
		glVertex3f(-x, y, -3.0);
		glVertex3f(-5.0, 0.0, -3.0);
		glVertex3f(-x, -y, -3.0);
		glVertex3f(0.0, -5.0, -3.0);
		glVertex3f(x, -y, -3.0);
	glEnd();
}

// Dibuja el Octagono Coloreado

void renderColoredOctagone() {
	GLfloat x, y;
	x = 3.535533906; // 5 * cos(45)
	y = 3.535533906; // 5 * sin(45)

	glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
			glVertex3f(5.0, 0.0, -3.0);
		glColor3f(0.0, 1.0, 0.0);
			glVertex3f(x, y, -3.0);
		glColor3f(0.0, 0.0, 1.0);
			glVertex3f(0.0, 5.0, -3.0);
		glColor3f(1.0, 1.0, 0.0);
			glVertex3f(-x, y, -3.0);
		glColor3f(1.0, 0.0, 1.0);
			glVertex3f(-5.0, 0.0, -3.0);
		glColor3f(0.0, 1.0, 1.0);
			glVertex3f(-x, -y, -3.0);
		glColor3f(1.0, 0.5, 0.2);
			glVertex3f(0.0, -5.0, -3.0);
		glColor3f(0.0, 0.3, 0.7);
			glVertex3f(x, -y, -3.0);
	glEnd();
}

void init(void) {
	glClearColor (0.0, 0.0, 0.0, 0.0);
}


void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 27:
			exit(0);
		break;
		case 'e':
		case 'E':
			printf("SE PRESIONO LA TECLA E\n");
			isE ^= true;
		break;
		case 'p':
		case 'P':
			printf("SE PRESIONO LA TECLA P\n");
			isE ^= true;
		break;
	}
}

void display(void) {
   glClear (GL_COLOR_BUFFER_BIT);
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glLoadIdentity();

   //renderOctagone();
   
   if(isE)
	   renderTriangleCross();
   else
	   renderColoredOctagone();
   
   glFlush();
}

void idleFunc(void) {
	glutPostRedisplay();
}

void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(45, (GLfloat)width / (GLfloat)height, 0.01, 100.0);
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.025, 100);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Tarea 02 JEPF");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(idleFunc);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
