
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

   float *M;
   int i, j;


   defineHouse(&faces[0]);
   glColor3f (1.0, 1.0, 1.0);

/* ONLY MODIFY CODE BELOW */

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity ();             /* clear the matrix */

   // Let's manually move the camera back

   //glTranslatef(0.0, 0.0, -10.0);

   // Now explicitly place the camera

   gluLookAt (camPosX, camPosY, camPosZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);


/* DO NOT MODIFY ANYTHING ELSE */

   /* Draw a coordinate axis */

   glEnable(GL_DEPTH_TEST);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   drawAxes(5);
   drawHouse(&faces[0]);
   glutSwapBuffers();

}

#endif
