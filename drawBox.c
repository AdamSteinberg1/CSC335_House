#ifndef DRAWBOX
#define DRAWBOX

#include "opengl.h"
#include "structs.h"

extern float angle;
void drawBox( struct face *faces )
{
    int i, j;

    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);

    glPushMatrix();
    glRotatef(angle,0.0,0.0,1.0);

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

    glPopMatrix();


}

#endif
