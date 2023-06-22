/*
Create a POLYGON
 */
#include <windows.h>  // for MS Windows 
#include <GL/glut.h>  // GLUT, include glu.h and gl.h 
 
/* Initialize OpenGL Graphics */
void initializeGL() {
// Set "clearing" or background color 
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque 
glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0 , 15.0);
 
}
 
/* Display function */

void display() {
   glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color 
 
   // Define shapes enclosed within a pair of glBegin and glEnd 
 
   glBegin(GL_POLYGON);          // Each set of 6 vertices form a hexagon(polygon)
      glColor3f(1.0f, 0.0f, 1.0f); //Purple
      glVertex2f(-2.0f, -5.0f);
      glVertex2f(2.0f, -5.0f);
      glVertex2f(6.0f, 0.0f);
      glVertex2f(2.0f, 5.0f);
      glVertex2f(-2.0f, 5.0f);
      glVertex2f(-6.0f, 0.0f);
   glEnd();
 
   glFlush();  // Render now 
}
 
/* Main function: */

int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT 
   glutCreateWindow("POLYGON");  // Create window with the given title 
   glutInitWindowSize(320, 320);   // Set the window's initial width & height 
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner 
   glutDisplayFunc(display);       // Register callback handler for window re-paint event 
   initializeGL();                  // Our own OpenGL initialization 
   glutMainLoop();                 // Enter the event-processing loop 
   return 0;
}