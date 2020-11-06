#include "opengl.h"
#include "prototypes.h"
#include <stdio.h>

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

extern float angularVelocityX;
extern float angularVelocityY;
extern float angularVelocityZ;


void modifyVelocity(int x, int y, bool increase)
{
  const float delta = 0.5; //how much each click changes the angular velocity
  const float limit = 10;  //the maximum angulat speed

  if(x<WINDOW_WIDTH/2) //left side
  {
    if(y > x) //top left corner
    {
      if(increase) //left click
      {
        angularVelocityY += delta;
        if(angularVelocityY > limit)
          angularVelocityY = limit;
      }
      else //right click
      {
        angularVelocityY -= delta;
        if(angularVelocityY < -limit)
          angularVelocityY = -limit;
      }
    }
    else //bottom
    {
      if(increase) //left click
      {
        angularVelocityZ += delta;
        if(angularVelocityZ > limit)
          angularVelocityZ = limit;
      }
      else //right click
      {
        angularVelocityZ -= delta;
        if(angularVelocityZ < -limit)
          angularVelocityZ = -limit;
      }
    }
  }
  else  //right side
  {
    if(y > WINDOW_HEIGHT - x) //top right corner
    {
      if(increase) //left click
      {
        angularVelocityX += delta;
        if(angularVelocityX > limit)
          angularVelocityX = limit;
      }
      else //right click
      {
        angularVelocityX -= delta;
        if(angularVelocityX < -limit)
          angularVelocityX = -limit;
      }
    }
    else //bottom
    {
      printf("bottom\n");
      if(increase) //left click
      {
        angularVelocityZ += delta;
        if(angularVelocityZ > limit)
          angularVelocityZ = limit;
      }
      else //right click
      {
        angularVelocityZ -= delta;
        if(angularVelocityZ < -limit)
          angularVelocityZ = -limit;
      }
    }
  }
}

void mouse(int button, int state, int x, int y)
{
// Handler for mouse interaction
    switch (button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            {
                modifyVelocity(x,WINDOW_HEIGHT-y,true);
            }
            break;


        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
            {
              modifyVelocity(x,WINDOW_HEIGHT-y,false);
            }
            break;
    }
}



void keyboard( unsigned char key, int x, int y )
{
  switch (key)
  {
    case 'q':
    case 'Q':
      exit(0);
      break;
  }
}
