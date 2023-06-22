/* 3D KIVOS ROTATE */

#include <windows.h>
#include <GL/glut.h>

char title[] = "3D KIVOS ROTATE";

GLfloat angleCube = 0.0f;
int refreshMillis = 15;

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClearDepth(1.0f);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);
   glShadeModel(GL_SMOOTH);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glTranslatef(1.5f, 0.0f, -7.0f);
	glRotatef(angleCube, 1.0f, 1.0f, 1.0f);


	glBegin(GL_QUADS);		// Each	set of 4 vertices form a quad

 	  // top
 	  glColor3f(0.0f, 1.0f, 0.0f);	// Green
 	  glVertex3f(1.0f, 1.0f, -1.0f); // x, y, depth
 	  glVertex3f(-1.0f, 1.0f, -1.0f);	
 	  glVertex3f(-1.0f, 1.0f, 1.0f);	
 	  glVertex3f(1.0f, 1.0f, 1.0f);	

	 
 	  // bottom
 	  glColor3f(1.0f, 0.5f, 0.0f);	// Orange				
 	  glVertex3f(1.0f, -1.0f, 1.0f); // x, y, depth
 	  glVertex3f(-1.0f, -1.0f, 1.0f);	
 	  glVertex3f(-1.0f, -1.0f, -1.0f);	
 	  glVertex3f(1.0f, -1.0f, -1.0f);	
	

 	  // front
 	  glColor3f(1.0f, 0.f, 0.0f);	// red	
 	  glVertex3f(1.0f, 1.0f, 1.0f); 
 	  glVertex3f(-1.0f, 1.0f, 1.0f);	
 	  glVertex3f(-1.0f, -1.0f, 1.0f);	
 	  glVertex3f(1.0f, -1.0f, 1.0f);	
	

 	  // back
 	  glColor3f(1.0f, 1.0f, 0.0f);	// yellow	
 	  glVertex3f(1.0f, -1.0f, -1.0f); 
 	  glVertex3f(-1.0f, -1.0f, -1.0f);	
 	  glVertex3f(1.0f, 1.0f, -1.0f);	


 	  // left
 	  glColor3f(0.0f, 0.0f,	1.0f);	// blue
 	  glVertex3f(-1.0f, 1.0f, -1.0f);	
 	  glVertex3f(-1.0f, -1.0f, -1.0f);	
 	  glVertex3f(-1.0f, -1.0f, 1.0f);


 	  // right
 	  glColor3f(1.0f, 0.0f,	1.0f);	// magenta
 	  glVertex3f(1.0f, 1.0f, 1.0f);	
 	  glVertex3f(1.0f, -1.0f, 1.0f);	
 	  glVertex3f(1.0f, -1.0f, -1.0f);
      glEnd();

  glutSwapBuffers();

  angleCube -= 0.15f;
}



void Timer(int value) {
   glutPostRedisplay();    // Post a paint request to activate display()
   glutTimerFunc(refreshMillis, Timer, 0); // subsequent timer call at milliseconds
}


void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer

   if (height == 0) height = 1;                
   GLfloat aspect = (GLfloat)width / (GLfloat)height;   

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);	 //
}


int main(int argc, char** argv) {
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_DOUBLE);	//xrisimopioite otan exoume perptosis(translet,rotate,...)
 glutInitWindowSize(640,480);
 glutInitWindowPosition(50,50);
 glutCreateWindow(title);
 glutDisplayFunc(display);
 glutReshapeFunc(reshape);
 initGL();
 glutTimerFunc(0, Timer, 0);  
 glutMainLoop();               
 return 0;
}