/*
Create a Triangle
 */
#include <windows.h>  // for MS Windows 
#include <GL/glut.h>  // GLUT, include glu.h and gl.h 
 
/* Initialize OpenGL Graphics */
void initializeGL() {
// Set "clearing" or background color 
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque 
}
 
/* Display function */

void display2() {
   glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color 
 
   // Define shapes enclosed within a pair of glBegin and glEnd 
 
   glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle 
      glColor3f(0.0f, 0.0f, 1.0f); // Blue 
      glVertex2f(0.1f, -0.6f);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(0.7f, -0.6f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex2f(0.4f, -0.1f);
   glEnd();
 
   glFlush();  // Render now 
}
 
/* Main function: */

int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT 
   glutCreateWindow("Triangle");  // Create window with the given title 
   glutInitWindowSize(320, 320);   // Set the window's initial width & height 
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner 
   glutDisplayFunc(display2);       // Register callback handler for window re-paint event 
   initializeGL();                  // Our own OpenGL initialization 
   glutMainLoop();                 // Enter the event-processing loop 
   return 0;
}