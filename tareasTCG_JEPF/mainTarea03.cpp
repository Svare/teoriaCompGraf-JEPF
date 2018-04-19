/*
	Pacheco Franco Jesús Enrique
*/

#include <GL\glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isE = true;

float trasZ = 0.0f;
float rotY = 0.0f;

void prismaRectangular(float longitud, float altura, float anchura) {
	GLfloat x, y, z;

	x = longitud / 2;
	y = altura / 2;
	z = anchura / 2;

	GLfloat vertexes[8][3] = {
								{ -x,y,-z },
								{ x,y,-z },
								{ x,y,z },
								{ -x,y,z },
								{ -x,-y,-z },
								{ -x,-y,z },
								{ x,-y,z },
								{ x,-y,-z },
							};
	
	glBegin(GL_QUADS); // FRONT
		glColor3f(0.5f, 1.0f, 0.5f);
		glVertex3fv(vertexes[0]);
		glVertex3fv(vertexes[4]);
		glVertex3fv(vertexes[7]);
		glVertex3fv(vertexes[1]);
	glEnd();

	glBegin(GL_QUADS); // BACK
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3fv(vertexes[3]);
		glVertex3fv(vertexes[2]);
		glVertex3fv(vertexes[6]);
		glVertex3fv(vertexes[5]);
	glEnd();

	glBegin(GL_QUADS); // LEFT
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3fv(vertexes[0]);
		glVertex3fv(vertexes[3]);
		glVertex3fv(vertexes[5]);
		glVertex3fv(vertexes[4]);
	glEnd();

	glBegin(GL_QUADS); // RIGHT
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3fv(vertexes[1]);
		glVertex3fv(vertexes[7]);
		glVertex3fv(vertexes[6]);
		glVertex3fv(vertexes[2]);
	glEnd();

	glBegin(GL_QUADS); // TOP
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3fv(vertexes[0]);
		glVertex3fv(vertexes[1]);
		glVertex3fv(vertexes[2]);
		glVertex3fv(vertexes[3]);
	glEnd();

	glBegin(GL_QUADS); // BOTTOM
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3fv(vertexes[4]);
		glVertex3fv(vertexes[5]);
		glVertex3fv(vertexes[6]);
		glVertex3fv(vertexes[7]);
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
		
		case 'z':
		case 'Z':
			trasZ -= 0.2f;
			break;
		case 'x':
		case 'X':
			trasZ += 0.2f;
			break;
		case 'e':
		case 'E':
			rotY += 0.5f;
			break;
		case 'p':
		case 'P':
			rotY -= 0.5f;
		break;
	}
}

void display(void) {
   glClear (GL_COLOR_BUFFER_BIT);
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glLoadIdentity();

   // Codigo a Dibujar

   glTranslatef(0.0f, 0.0f, -2.0f + trasZ);
   glRotatef(rotY, 0.0f, 1.0f, 0.0f);
   prismaRectangular(1.0f, 1.0f, 1.0f);
  
   
   glFlush();
}

void idleFunc(void) {
	glutPostRedisplay();
}

void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (GLfloat)width / (GLfloat)height, 0.01, 100.0);
	//frustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Tarea 03 JEPF");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(idleFunc);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
