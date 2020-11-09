#ifndef RESHAPE
#define RESHAPE

#include "opengl.h"
#include <iostream>
#include <string>

extern float camPosX;
extern float camPosY;
extern float camPosZ;
extern int viewMode;

void promptCustom()
{
  bool ortho = false;
  std::string response;
  float left, right, bottom, top, near, far;
  std::cout << "\nOrthographic Projection? (y/n) ";
  std::cin >> response;
  if(response == "y" || response == "Y")
  {
    ortho = true;
  }
  std::cout << "\nLeft: ";
  std::cin >> left;
  std::cout << "\nRight: ";
  std::cin >> right;
  std::cout << "\nBottom: ";
  std::cin >> bottom;
  std::cout << "\nTop: ";
  std::cin >> top;
  std::cout << "\nNear: ";
  std::cin >> near;
  std::cout << "\nFar: ";
  std::cin >> far;

  if(ortho)
  {
    glOrtho(left, right, bottom, top, near, far);
  }
  else
  {
    glFrustum(left, right, bottom, top, near, far);
  }

}

void changeProjection()
{
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  float farPlane = camPosX + camPosY + camPosZ;
  switch (viewMode)
  {
     case 1: //perspective
       glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, farPlane);
       break;
     case 2: //orthographic
       glOrtho(-5.0, 5.0, -5.0, 5.0, 1.0, 20);
       break;
     case 3: //custom
     {
       promptCustom();
     }
  }
  glMatrixMode (GL_MODELVIEW);
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   changeProjection();
}

#endif
