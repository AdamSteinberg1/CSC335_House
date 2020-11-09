#ifndef MENU
#define MENU

#include "opengl.h"
#include "prototypes.h"

extern float camPosX;
extern float camPosY;
extern float camPosZ;
extern float angleX;
extern float angleY;
extern float angleZ;
extern float angularVelocityX;
extern float angularVelocityY;
extern float angularVelocityZ;
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
bool wireframeEnabled = false;
bool axisEnabled = true;
bool helloWorldEnabled = true;
int viewMode = 1;

void onMainMenu(int msg)
{
  switch (msg)
  {
    case 1: //Reset
      camPosX = 6.0;
      camPosY = 5.0;
      camPosZ = 3.0;
      angleX = 0.0;
      angleY = 0.0;
      angleZ = 0.0;
      angularVelocityX = 0.0;
      angularVelocityY = 0.0;
      angularVelocityZ = 0.0;
      break;
    case 2: //Exit
      exit(0);
      break;
  }
}

void onView(int msg)
{
  switch (msg)
  {
    case 1: //Perspective
      viewMode = 1;
      break;
    case 2: //Orthographic
      viewMode = 2;
      break;
    case 3: //Custom
      viewMode = 3;
      break;
  }
  changeProjection();
}

void onWireframe(int msg)
{
  wireframeEnabled = msg == 1;
}

void onAxis(int msg)
{
  axisEnabled = msg == 1;
}

void onHelloWorld(int msg)
{
  helloWorldEnabled = msg == 1;
}

void createMenus()
{
  int view = glutCreateMenu(onView);
  glutAddMenuEntry("Perspective", 1);
  glutAddMenuEntry("Orthographic", 2);
  glutAddMenuEntry("Custom", 3);

  int wireframe = glutCreateMenu(onWireframe);
  glutAddMenuEntry("On", 1);
  glutAddMenuEntry("Off", 2);

  int axis = glutCreateMenu(onAxis);
  glutAddMenuEntry("On", 1);
  glutAddMenuEntry("Off", 2);

  int helloWorld = glutCreateMenu(onHelloWorld);
  glutAddMenuEntry("On", 1);
  glutAddMenuEntry("Off", 2);

  // And now create the menu
  int mainMenu = glutCreateMenu(onMainMenu);
  glutAddMenuEntry("Reset", 1);
  glutAddSubMenu("View", view);
  glutAddSubMenu("Wireframe", wireframe);
  glutAddSubMenu("Axis", axis);
  glutAddSubMenu("Hello World", helloWorld);
  glutAddMenuEntry("Exit", 2);

  glutAttachMenu(GLUT_MIDDLE_BUTTON);
}

#endif
