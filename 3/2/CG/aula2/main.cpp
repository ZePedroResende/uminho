#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <iostream>
using namespace std;

float rotatex=0;
float rotatey=0;
float rotatez=0;
float transx = 0;
float transy = 0;
float transz = 0;
float scalx = 1;
float scaly = 1;
float scalz = 1;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}

void pyramid(){

  glRotatef(rotatex,1,0,0);
  glRotatef(rotatey,0,1,0);
  glRotatef(rotatez,0,0,1);
	glTranslatef(transx,0,0);
	glTranslatef(0,0,transz);
//  angulo+=10;

	glBegin( GL_TRIANGLES );
		glVertex3f(1.0f,0.0f,0.0f);
		glVertex3f(-1.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,-1.0f);

		glVertex3f(-1.0f,0.0f,0.0f);
		glVertex3f(1.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,1.0f);

		glVertex3f(1.0f,0.0f,0.0f);
		glVertex3f(0.0f,1.0f,0.0f);
		glVertex3f(0.0f,0.0f,1.0f);

		glVertex3f(0.0f,0.0f,-1.0f);
		glVertex3f(0.0f,1.0f,0.0f);
		glVertex3f(1.0f,0.0f,0.0f);

		glVertex3f(0.0f,1.0f,0.0f);
		glVertex3f(0.0f,0.0f,-1.0f);
		glVertex3f(-1.0f,0.0f,0.0f);

		glVertex3f(0.0f,1.0f,0.0f);
		glVertex3f(-1.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,1.0f);
	glEnd();
}

void axis_system(){
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0);
		glVertex3f(0,0,0);
		glVertex3f(10,0,0);

		glColor3f(0.0,1.0,0.0);
		glVertex3f(0,0,0);
		glVertex3f(0,10,0);

		glColor3f(0.0,0.0,1.0);
		glVertex3f(0,0,0);
		glVertex3f(0,0,3);
	glEnd();
}

void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(10.0,3.0,10.0,
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

// put the geometric transformations here
//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
//glDisable();
// put drawing instructions here
  pyramid();
  axis_system();
	// End of frame
	glutSwapBuffers();
}



// write function to process keyboard events

void keyboard_handler(unsigned char key, int x, int y){
  switch(key)
  {
    case 'a':
    rotatex+=10;
    break;
    case 'b':
    rotatex-=10;
    break;
    case 'w':
    rotatey+=10;
    break;
    case 's':
    rotatey-=10;
    break;
    case 'q':
    rotatez+=10;
    break;
    case 'e':
    rotatez-=10;
    break;
		case('o'):
			glPolygonMode(GL_FRONT, GL_LINE);
			break;
		case('p'):
			glPolygonMode(GL_FRONT, GL_POINT);
			break;
		case('f'):
			glPolygonMode(GL_FRONT, GL_FILL);
			break;
		case('l'):
			transx+=0.1;
			break;
		case('j'):
			transx-=0.1;
			break;
		case('i'):
			transz-=0.1;
			break;
		case('k'):
			transz+=0.1;
			break;
		case('z'):
			scalz+=0.1;
			break;
		case('x'):
			scalx+=0.1;
			break;
		case('y'):
			scaly+=0.1;
			break;
		default:
			break;
  }
}

int main(int argc, char **argv) {

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");

// Required callback registry
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
  glutIdleFunc(renderScene);

// put here the registration of the keyboard callbacks

  glutKeyboardFunc(keyboard_handler);
//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}
