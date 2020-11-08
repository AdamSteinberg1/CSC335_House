#ifndef RESHAPE
#define RESHAPE

#include "opengl.h"

extern float camPosX;
extern float camPosY;
extern float camPosZ;
extern int viewMode;


void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   float farPlane = camPosX + camPosY + camPosZ;
   switch (viewMode)
   {
     case 1:
        glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, farPlane);
        break;
     case 2:
        glOrtho(-5.0, 5.0, -5.0, 5.0, 1.0, 20);
        break;
   }
   glMatrixMode (GL_MODELVIEW);
}

#endif
