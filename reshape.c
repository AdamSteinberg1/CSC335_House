#ifndef RESHAPE
#define RESHAPE

#include "opengl.h"

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   //glOrtho   (-10.0, 10.0, -10.0, 10.0, 1.0, 20.0);
    
   glMatrixMode (GL_MODELVIEW);
}

#endif
