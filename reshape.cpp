#ifndef RESHAPE
#define RESHAPE

#include "opengl.h"

extern float camPosX;
extern float camPosY;
extern float camPosZ;


void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   float farPlane = camPosX + camPosY + camPosZ;
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, farPlane);
   //glOrtho   (-10.0, 10.0, -10.0, 10.0, 1.0, 20.0);

   glMatrixMode (GL_MODELVIEW);
}

#endif
