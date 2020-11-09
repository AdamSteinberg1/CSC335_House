#include "opengl.h"
#include "prototypes.h"
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

extern float angularVelocityX;
extern float angularVelocityY;
extern float angularVelocityZ;
extern float angleX;
extern float angleY;
extern float angleZ;
extern float camPosX;
extern float camPosY;
extern float camPosZ;
extern int viewMode;


void modifyVelocity(int x, int y, bool increase)
{
  const float delta = 0.5; //how much each click changes the angular velocity
  const float limit = 10;  //the maximum angular speed

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

    case 'R':
      camPosX = 6.0;
      camPosY = 5.0;
      camPosZ = 3.0;
    case 'r':
      angleX = 0.0;
      angleY = 0.0;
      angleZ = 0.0;

    case 's':
    case 'S':
      angularVelocityX = 0.0;
      angularVelocityY = 0.0;
      angularVelocityZ = 0.0;
      break;


  }
}

void keyboardSpecial(int key, int x, int y)
{
  //we only want to move the camera in perspective mode
  if(viewMode != 1)
    return;

  switch (key)
  {
    case GLUT_KEY_PAGE_UP:
      camPosX *= 0.9;
      camPosY *= 0.9;
      camPosZ *= 0.9;
      break;
    case GLUT_KEY_PAGE_DOWN:
      camPosX *= 1.1;
      camPosY *= 1.1;
      camPosZ *= 1.1;
      break;
  }
  changeProjection();
}
