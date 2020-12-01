#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <cassert>
//Here we define the vertices
const float A = .525f;
const float B = .850f;
const float C = 0.0f;
static GLfloat vert[12][3] =
{
 {-A,C,B}, {A,C,B}, {-A,C,-B}, {A,C,-B},
 {C,B,A}, {C,B,-A}, {C,-B,A}, {C,-B,-A},
 {B,A,C}, {-B,A, C}, {B,-A,C}, {-B,-A, C}
};
//Triangle indices
static GLuint tri[20][3] =
{
 {0,4,1},{0,9,4},{9,5,4},{4,5,8},{4,8,1},
 {8,10,1},{8,3,10},{5,3,8},{5,2,3},{2,7,3},
 {7,10,3},{7,6,10},{7,11,6},{11,0,6},{0,1,6},
 {6,1,10},{9,0,11},{9,11,2},{9,2,5},{7,2,11}
};
//Here we normalize a vector
void Normalize(float v[3])
{
	float d = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	assert(d > 0);
	v[0] = v[0] / d;
	v[1] = v[1] / d;
	v[2] = v[2] / d;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	int i;
	glBegin(GL_TRIANGLES);
	for (i = 0; i < 20; i++) {
			glColor3f(1.0, 0.0, 0.0);
			glVertex3fv(&vert[tri[i][0]][0]);
			glVertex3fv(&vert[tri[i][1]][0]);
			glVertex3fv(&vert[tri[i][2]][0]);
		}
		
	glEnd();
	glutSwapBuffers();
	
}


void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 0.0, 0.0, 0.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("IcosaHedron");
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
	