//ИЭмб 2 
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
 

GLfloat ballRadius = 0.3f;
GLfloat ballX = 0.0f;
GLfloat ballY = 0.0f;
GLfloat xSpeed = 0.02;
GLfloat ySpeed = 0.007f;
int refreshMillis = 30;
GLfloat ballXMax, ballXMin, ballYMax, ballYMin;
GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;

bool stopball = true;

/* Initialize OpenGL Graphics */
void initGL() 
{
 glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
}

void display() 
{

 glClear(GL_COLOR_BUFFER_BIT);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();


 glTranslatef(ballX, ballY, 0.0f);

 glBegin(GL_TRIANGLE_FAN);
      glColor3f(1.0f, 0.0f, 1.0f);  // Roz
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

if (ballX > ballXMax) {
      ballX = ballXMax;
      xSpeed = -xSpeed;
   } else if (ballX < ballXMin) {
      ballX = ballXMin;
      xSpeed = -xSpeed;
   }
   if (ballY > ballYMax) {
      ballY = ballYMax;
      ySpeed = -ySpeed;
   } else if (ballY < ballYMin) {
      ballY = ballYMin;
      ySpeed = -ySpeed;
   }
 
}


void reshape(GLsizei width, GLsizei height) {
   
   if (height == 0) height = 1;                
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);  
   glLoadIdentity();             
   if (width >= height) {
      clipAreaXLeft   = -1.0 * aspect;
      clipAreaXRight  = 1.0 * aspect;
      clipAreaYBottom = -1.0;
      clipAreaYTop    = 1.0;
   } else {
      clipAreaXLeft   = -1.0;
      clipAreaXRight  = 1.0;
      clipAreaYBottom = -1.0 / aspect;
      clipAreaYTop    = 1.0 / aspect;
   }

   gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop);
   ballXMin = clipAreaXLeft + ballRadius;
   ballXMax = clipAreaXRight - ballRadius;
   ballYMin = clipAreaYBottom + ballRadius;
   ballYMax = clipAreaYTop - ballRadius;
}


void Timer(int value) 
{
   glutPostRedisplay();    // Post a paint request to activate display()
   glutTimerFunc(refreshMillis, Timer, 0); // subsequent timer call at milliseconds
}




// Buttons

void keyboard(unsigned char key, int x, int y) {
   switch (key) {
      case 'a':
	stopball = !stopball;       
        if (stopball) { 
	  xSpeed = 0;
	  ySpeed = 0;        
         } else {                 
           ballX += xSpeed;
           ballY += ySpeed; 
         }
         break;
	 case 'e':     
         exit(0);
         break;
   }
display();
}



int main(int argc, char** argv) {
   glutInit(&argc, argv);           
   glutInitDisplayMode(GLUT_DOUBLE); 
   glutInitWindowSize(windowsWidth, windowHeight);  
   glutInitWindowPosition(windowsPosX, windowsPosY); 
   glutCreateWindow("Moving Ball");    
   glutDisplayFunc(display);     
   glutReshapeFunc(reshape);     
   glutTimerFunc(0, Timer, 0);  
   glutFullScreen();             
   glutKeyboardFunc(keyboard);
   initGL();                     
   glutMainLoop();               
   return 0;
}