
#ifndef DRAW_AXES
#define DRAW_AXES

#include "opengl.h" 

void drawAxes(int length)
{   

/* This provides a coordinate axis about the origin. */
   glPointSize(1.0);
   glBegin(GL_LINES);
     glVertex3i(0,length,0);
     glVertex3i(0,-length,0);
   glEnd();
   glBegin(GL_LINES);
     glVertex3i(length,0,0);
     glVertex3i(-length,0,0);
   glEnd();
   glBegin(GL_LINES);
     glVertex3i(0,0,length);
     glVertex3i(0,0,-length);
   glEnd();
}

#endif
