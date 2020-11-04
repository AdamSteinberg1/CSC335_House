#include "opengl.h"
float angle = 0.0f;

void updateRotations()
{
  angle += 0.1;

  glutPostRedisplay();
}
