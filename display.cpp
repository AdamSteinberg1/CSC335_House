
#ifndef DISPLAY
#define DISPLAY

#include "opengl.h"
#include "structs.h"

#include "prototypes.h"

float camPosX = 6.0;
float camPosY = 5.0;
float camPosZ = 3.0;

void display(void)
{

   struct face faces[7];

   defineHouse(&faces[0]);
   glColor3f (1.0, 1.0, 1.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity ();             /* clear the matrix */
   gluLookAt (camPosX, camPosY, camPosZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);


   glEnable(GL_DEPTH_TEST);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


   drawAxes(5);
   drawHouse(&faces[0]);

   drawText();


   glutSwapBuffers();

}

#endif
