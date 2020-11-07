#include "opengl.h"
void onAxis(int msg)
{

}

void onSphere(int msg)
{

}

void doNothing(int msg)
{
}

void createMenus()
{
  // Let's add a menu item //
  int axis = glutCreateMenu(onAxis);
  glutAddMenuEntry("On", 1);
  glutAddMenuEntry("Off", 2);

  // Let's add another menu item
  int sphere = glutCreateMenu(onSphere);
  glutAddMenuEntry("On", 1);
  glutAddMenuEntry("Off", 2);

  // And now create the menu
  int menu = glutCreateMenu(doNothing);
  glutAddSubMenu("Axes", axis);
  glutAddSubMenu("Sphere", sphere);

  glutAttachMenu(GLUT_MIDDLE_BUTTON);
}
