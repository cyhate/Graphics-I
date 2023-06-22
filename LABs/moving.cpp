// Moving Ball

#include <windows.h>
#include <GL/glut.h>
#include <Math.h> 
#define PI 3.14f

// Global Variables

int windowsWidth = 640;
int windowHeight = 480;
int windowsPosX = 50;
int windowsPosY = 50;

GLfloat ballRadius = 0.5f;
GLfloat ballX = 0.0f;
GLfloat ballY = 0.0f;
GLfloat xSpeed = 0.02;
GLfloat ySpeed = 0.007f;
int refreshMillis = 30;

/* Initialize OpenGL Graphics */
void initGL() {
glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
}

void display() {
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0 , 15.0);

glTranslatef(ballX, ballY, 0.0f);

glBegin(GL_TRIANGLE_FAN);
      glColor3f(0.0f, 0.0f, 1.0f);  // Blue
      glVertex2f(0.0f, 0.0f);       // Center of circle
      int numSegments = 100;
      GLfloat angle;
      for (int i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
         angle = i * 2.0f * PI / numSegments;  // 360 deg for all segments
         glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
      }
glEnd();

glutSwapBuffers();

ballX += xSpeed;
ballY += ySpeed;

}


void Timer(int value) {
   glutPostRedisplay();    // Post a paint request to activate display()
   glutTimerFunc(refreshMillis, Timer, 0); // subsequent timer call at milliseconds
}


int main(int argc, char** argv){
glutInit(&argc,argv);
glutCreateWindow("Moving Ball");
glutInitDisplayMode(GLUT_DOUBLE);
glutInitWindowSize(windowsWidth,windowHeight);
glutInitWindowPosition(windowsPosX,windowsPosY);
glutTimerFunc(0, Timer, 0);  
glutDisplayFunc(display);
initGL();
glutMainLoop();
return 0;
}