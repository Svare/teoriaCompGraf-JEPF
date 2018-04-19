
#include <GL\glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define PI 3.14159265359

bool isE = true;

float trasZ = 0.0f;
float rotX = 0.0f, rotY = 0.0f;

float degreesToRadians(float degrees) {
	return (float)(degrees*PI) / 180;
}

void renderConeCylinder(int snippets, float topRadius, float lowRadius, float height, int wired) {
	float currentAngle = 0, halfHeight, snippet, *topX, *lowX, *topZ, *lowZ;

	snippet = 360 / snippets;
	halfHeight = height / 2;

	// Reservamos memoria para guardar todos los vértices de ambas tapas

	topX = (float*)malloc(sizeof(float)*(snippets + 1));
	lowX = (float*)malloc(sizeof(float)*(snippets + 1));
	topZ = (float*)malloc(sizeof(float)*(snippets + 1));
	lowZ = (float*)malloc(sizeof(float)*(snippets + 1));

	if (topX != NULL && lowX != NULL && topZ != NULL && lowZ != NULL) {
		for (int i = 0; i < snippets; i++) {
			topX[i] = topRadius * cos(degreesToRadians(currentAngle));
			topZ[i] = topRadius * sin(degreesToRadians(currentAngle));
			lowX[i] = lowRadius * cos(degreesToRadians(currentAngle));
			lowZ[i] = lowRadius * sin(degreesToRadians(currentAngle));

			currentAngle += snippet;
		}
	}

	topX[snippets] = topX[0];
	topZ[snippets] = topZ[0];
	lowX[snippets] = lowX[0];
	lowZ[snippets] = lowZ[0];

	for (int i = 0; i < snippets; i++) {
		if (wired)
			glBegin(GL_LINE_LOOP);
		else
			glBegin(GL_TRIANGLES);
				glVertex3f(topX[i], halfHeight, topZ[i]);
				glVertex3f(0.0f,halfHeight, 0.0f);
				glVertex3f(topX[i+1], halfHeight, topZ[i+1]);
			glEnd();
		if(wired)
			glBegin(GL_LINE_LOOP);
		else
			glBegin(GL_QUADS);
				glVertex3f(topX[i], halfHeight, topZ[i]);
				glVertex3f(topX[i+1], halfHeight, topZ[i+1]);
				glVertex3f(lowX[i+1], -halfHeight, lowZ[i+1]);
				glVertex3f(lowX[i], -halfHeight, lowZ[i]);
			glEnd();
		if(wired)
			glBegin(GL_LINE_LOOP);
		else
			glBegin(GL_TRIANGLES);
				glVertex3f(lowX[i], -halfHeight, lowZ[i]);
				glVertex3f(0.0f,-halfHeight, 0.0f);
				glVertex3f(lowX[i+1], -halfHeight, lowZ[i+1]);
			glEnd();
	}

	free(topX);
	free(topZ);
	free(lowX);
	free(lowZ);	
}


void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
}


void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 27:
			exit(0);
			break;
		case 'w':
		case 'W':
			trasZ -= 0.5f;
			break;
		case 's':
		case 'S':
			trasZ += 0.5f;
			break;
	}
}

void specialKeys(int a_keys, int x, int y) {
	switch (a_keys) {
		case GLUT_KEY_UP:
			rotX -= 0.5f;
			break;
		case GLUT_KEY_DOWN:
			rotX += 0.5f;
			break;
		case GLUT_KEY_LEFT:
			rotY -= 0.5f;
			break;
		case GLUT_KEY_RIGHT:
			rotY += 0.5f;
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glLoadIdentity();

	// Codigo a Dibujar

	glTranslatef(0.0f, 0.0f, -35.0f + trasZ);
	glRotatef(rotY, 0.0f, 1.0f, 0.0f);
	glRotatef(rotX, 1.0f, 0.0f, 0.0f);

	// Ejes de Referencia

	glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(100.0f, 0.0f, 0.0f);
		glColor3f(0.0, 1.0, 0.0);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 100.0f, 0.0f);
		glColor3f(0.0, 0.0, 1.0);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 100.0f);
	glEnd();

	glColor3f(0.3f, 0.6f, 0.3f);

	renderConeCylinder(30, 5, 10, 10, PI);

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
	//glFrustum(-1, 1, -1, 1, 0.01, 50);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tarea 05 Híbrido Cono-Cilindro JEPF");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(idleFunc);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	glutReshapeFunc(reshape);
	glutMainLoop();
	
	return 0;
}
