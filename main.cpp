#include <stdio.h>
#include <GL/glut.h>

int r;

void myInit (void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-350.0, 350.0, -350.0, 350.0);
}

void midPointCircleAlgo() {
	int x = 0;
	int y = r;
	float decision = 1 - r;

	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2d(x, y);

	while (y > x) {
		if (decision < 0) {
			x++;
			decision += 2*x+1;
		} else {
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		glVertex2d(x, y);
		glVertex2d(x, -y);
		glVertex2d(-y, -x);
		glVertex2d(-x, y);
		glVertex2d(-x, -y);
		glVertex2d(y, x);
		glVertex2d(y, -x);
		glVertex2d(-y, x);
	}
	glEnd();
}

void myDisplay(void) {
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	midPointCircleAlgo();

	glFlush ();
}

int main(int argc, char** argv) {

    printf("Enter Radius R:  ");
	scanf("%d", &r);

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (700, 700);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Mid Point Circle Drawing Alogrithm");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();
    return 0;
}
