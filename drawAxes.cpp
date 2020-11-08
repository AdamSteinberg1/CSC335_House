
#ifndef DRAW_AXES
#define DRAW_AXES

#include "opengl.h"
#include <string>

extern bool axisEnabled;

void drawAxes(int length)
{
    if(!axisEnabled)
      return;

    // Set up some character arrays for axis labels
    std::string xaxis = "X";
    std::string yaxis = "Y";
    std::string zaxis = "Z";

    // Select the Stroke font we want to use
    void *font = GLUT_STROKE_ROMAN;

    // This provides a coordinate axis about the origin.
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

    // And now we  add some lettering.

    // Z - Label
    glPushMatrix();
    glTranslatef(-0.2, 0.2, 4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.002,0.002,0.002);
    for (char c : zaxis) {
        glutStrokeCharacter(font, c);
    }
    glPopMatrix();

    // Y - Label
    glPushMatrix();
    glTranslatef(0.0, 4, -.4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.002,0.002,0.002);
    for (char c : yaxis) {
        glutStrokeCharacter(font, c);
    }
    glPopMatrix();

    // X - Label
    glPushMatrix();
    glTranslatef(4.0, 0.0, -.4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glScalef(0.002,0.002,0.002);
    for (char c : xaxis) {
        glutStrokeCharacter(font, c);
    }
    glPopMatrix();
}

#endif
