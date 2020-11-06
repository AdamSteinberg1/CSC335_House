#include "opengl.h"


float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;

float angularVelocityX = 0.0f;
float angularVelocityY = 0.0f;
float angularVelocityZ = 0.0f;

void updateRotations()
{
  angleX += angularVelocityX;
  angleY += angularVelocityY;
  angleZ += angularVelocityZ;

  glutPostRedisplay();
}
