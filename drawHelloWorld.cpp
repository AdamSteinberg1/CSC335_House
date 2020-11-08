
#ifndef DRAW_HELLO_WORLD
#define DRAW_HELLO_WORLD

#include "opengl.h"
#include <string>

extern bool helloWorldEnabled;
void drawHelloWorld()
{
    if(!helloWorldEnabled)
      return;
    //the text to display
    std::string text = "Hello World!";

    glColor3f(1.0,1.0,0.0); //yellow color

    // Select the Stroke font we want to use
    void *font = GLUT_STROKE_ROMAN;

    // Z - Label
    glPushMatrix();
    glTranslatef(0.51, -0.7, 2.0);
    glRotatef(-45.0, 0.0,1.0,0.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.002,0.002,0.002);
    for (char c : text)
    {
        glutStrokeCharacter(font, c);
    }
    glPopMatrix();
}

#endif
