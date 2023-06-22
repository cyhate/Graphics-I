/*
 ÈÝìá 1
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
      glColor3f(0.0f, 1.0f, 1.0f); // GALAZIO 
      glVertex2f(0.6f, -0.5f);
      glVertex2f(0.3f, -0.2f);
      glColor3f(0.0f, 1.0f, 0.0f); //PRASINO
      glVertex2f(0.9f, -0.2f);
   glEnd();

   glBegin(GL_QUADS);		   // Each set of 4 vertices form a quad
      glColor3f(0.0f, 1.0f, 0.0f); // Green
      glVertex2f(-0.8f, 0.1f);      // x,y
      glVertex2f(-0.8f, 0.7f);
      glVertex2f(-0.4f, 0.7f);
      glVertex2f(-0.4f, 0.1f);	   
   glEnd();

   glBegin(GL_QUADS);		   // Each set of 4vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f); // kokkino
      glVertex2f(-0.8f, -0.6f);    // x,y
      glVertex2f(-0.8f, -0.0f);
      glVertex2f(-0.2f, -0.0f);
      glVertex2f(-0.2f, -0.6f);	
    glEnd();

   glBegin(GL_QUADS);		   // Each set of 4 vertices form a quad
      glColor3f(1.0f, 1.0f, 1.0f); // White
      glVertex2f(-0.6f, -0.3f);
      glColor3f(0.2f, 0.2f, 0.1f); // Gray
      glVertex2f(-0.6f, -0.1f);
      glColor3f(1.0f, 1.0f, 1.0f); // White
      glVertex2f(-0.9f, -0.1f);
      glColor3f(0.2f, 0.2f, 0.2f); // Gray
      glVertex2f(-0.9f, -0.3f);
   glEnd();

   glBegin(GL_POLYGON);            // Each set of 5 vertices form a polygon
      glColor3f(0.0f, 1.0f, 1.0f); // GALAZIO 
      glVertex2f(0.4f, 0.2f);
      glVertex2f(0.8f, 0.2f);
      glVertex2f(0.8f, 0.6f);
      glVertex2f(0.4f, 0.6f);
      glVertex2f(0.3f, 0.4f);
   glEnd();

 
   glFlush();  // Render now 
}
 
/* Main function: */

int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT 
   glutCreateWindow("ÈÝìá 1");  // Create window with the given title 
   glutInitWindowSize(800,600);   // Set the window's initial width & height 
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner 
   glutDisplayFunc(display2);       // Register callback handler for window re-paint event 
   initializeGL();                  // Our own OpenGL initialization 
   glutMainLoop();                 // Enter the event-processing loop 
   return 0;
}