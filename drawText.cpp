
#ifndef DRAW_TEXT
#define DRAW_TEXT

#include "globals.h"
#include "opengl.h"
#include <string>

extern int viewMode;

void drawText()
{

    //clear the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    //set the projection matrix to a 2D orthographic projection in pixel coordinates
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);


    std::string text;
    switch (viewMode)
    {
      case 1:
        text = "Perspective";
        break;
      case 2:
        text = "Orthographic";
        break;
      case 3:
        text = "Custom";
        break;
    }

    void* font = GLUT_BITMAP_HELVETICA_18;
    int textHeight = 18; //this font has a height of 18

    //calculate how many pixels wide the text is
    int textWidth = 0;
    for(char c: text)
    {
      textWidth += glutBitmapWidth(font, c);
    }


    glColor3f(1.0,1.0,1.0);
    //position on screen to start writing
    glRasterPos2i(WINDOW_WIDTH - textWidth, WINDOW_HEIGHT-textHeight);

    //write string
    for (char c : text)
    {
        glutBitmapCharacter(font, c);
    }

    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

#endif
