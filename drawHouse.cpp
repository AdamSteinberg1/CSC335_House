#ifndef DRAWHOUSE
#define DRAWHOUSE

#include "opengl.h"
#include "structs.h"
#include "prototypes.h"

extern float angleX;
extern float angleY;
extern float angleZ;
extern bool wireframeEnabled;
void drawHouse( struct face *faces )
{
    int i, j;

    if(wireframeEnabled)
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPushMatrix();
    glRotatef(angleX,1.0,0.0,0.0);
    glRotatef(angleY,0.0,1.0,0.0);
    glRotatef(angleZ,0.0,0.0,1.0);

    for(j=0;j<7;j++)
    {

        glColor3f(faces[j].color.red,
                  faces[j].color.green,
                  faces[j].color.blue);

        glBegin(GL_POLYGON);
        for (i=0;i<4;i++)
        {
            glVertex3f(faces[j].point[i].x,
                       faces[j].point[i].y,
                       faces[j].point[i].z);
        }
        glEnd();
    }

    drawHelloWorld();

    glPopMatrix();


}

#endif
