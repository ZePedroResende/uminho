#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>
float r= 5,a = 0,b = 0;
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


void drawCylinder(float radius, float height, int slices) {
  float angulo = (2*M_PI) /slices;
  glBegin(GL_TRIANGLES);
    for(int i = 0; i < slices; i++){
      glColor3f(1,0,0);
      glVertex3f(0,height,0);
      glVertex3f(radius*sin(angulo*i),height,radius*cos(angulo*i));
      glVertex3f(radius*sin(angulo*(i+1)),height,radius*cos(angulo*(i+1)));

      glColor3f(0,1,0);
      glVertex3f(radius*sin(angulo*i),height,radius*cos(angulo*i));
      glVertex3f(radius*sin(angulo*i),0,radius*cos(angulo*i));
      glVertex3f(radius*sin(angulo*(i+1)),height,radius*cos(angulo*(i+1)));


      glColor3f(0,0,1);
      glVertex3f(radius*sin(angulo*(i+1)),height,radius*cos(angulo*(i+1)));
      glVertex3f(radius*sin(angulo*i),0,radius*cos(angulo*i));
      glVertex3f(radius*sin(angulo*(i+1)),0,radius*cos(angulo*(i+1)));

      glColor3f(1,0,1);
      glVertex3f(radius*sin(angulo*i),0,radius*cos(angulo*i));
      glVertex3f(0,0,0);
      glVertex3f(radius*sin(angulo*(i+1)),0,radius*cos(angulo*(i+1)));
    }
  glEnd();
}


void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(r*sin(b)*cos(a), r*sin(b), r*cos(b)*cos(a),
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

	drawCylinder(1,2,100000);

	// End of frame
	glutSwapBuffers();
}


void processKeys(unsigned char key, int xx, int yy) {
  /*
  switch(key)
  {
    case 'w':
     r += 0.1
    break;
    case 's':
    r-=0.1;
    break;
    case 'a':
    a+=0.1;
    break;
    case 'd':
    b-=0.1;
    break;
		default:
			break;
  }
  */
  if(key =='w' ){
    r = r<1.5 ? r+0.1 : 1.5;
  }

  if(key =='s' ){
    r = r>-1.5 ? r-0.1 : -1.5;
  }

}

void processSpecialKeys(int key, int xx, int yy) {

// put code to process special keys in here

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

// Callback registration for keyboard processing
	glutKeyboardFunc(processKeys);
	glutSpecialFunc(processSpecialKeys);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}
