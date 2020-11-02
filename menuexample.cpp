#include <stdio.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static int DRAWAXIS = 0;
static int DRAWSPHERE = 0;

typedef struct vertex {
    float x;
    float y;
    float z;
    float w;
} vertex;

typedef struct colortype {
    float red;
    float green;
    float blue;
} colortype;

typedef struct house {
    vertex point[4];
    colortype color;	
} house;



void init(void) 
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}



void drawAxes(int length)
{   
    int i, len;

    // Set up some character arrays for axis labels
    char xaxis[] = "X"; 
    char yaxis[] = "Y";
    char zaxis[] = "Z";

    // Select the Stroke font we want to use
    void *font = GLUT_STROKE_ROMAN;

    // This provides a coordinate axis about the origin. 
    glPointSize(1.0);
    glBegin(GL_LINES);
    glVertex3i(0,length,0);
    glVertex3i(0,-length,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3i(length,0,0);
    glVertex3i(-length,0,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3i(0,0,length);
    glVertex3i(0,0,-length);
    glEnd();

    // And now we  add some lettering.

    // Z - Label
    glPushMatrix();
    glTranslatef(-0.2, 0.2, 4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.002,0.002,0.002);
    len = (int) strlen(zaxis);
    for (i = 0; i < len; i++) {
        glutStrokeCharacter(font, zaxis[i]);
    }
    glPopMatrix();

    // Y - Label
    glPushMatrix();
    glTranslatef(0.0, 4, -.4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.002,0.002,0.002);
    len = (int) strlen(yaxis);
    for (i = 0; i < len; i++) {
        glutStrokeCharacter(font, yaxis[i]);
    }
    glPopMatrix();

    // X - Label 
    glPushMatrix();
    glTranslatef(4.0, 0.0, -.4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(0.002,0.002,0.002);
    len = (int) strlen(xaxis);
    for (i = 0; i < len; i++) {
        glutStrokeCharacter(font, xaxis[i]);
    }
    glPopMatrix();
}

void drawSphere()
{
    glutWireSphere(3.0,20,20);
}


void display(void)
{
    const int DIMENSION=4;

    struct house faces[7];

    float *M;
    int i, j;



    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();             /* clear the matrix */
    gluLookAt (6.0, 5.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

    /* Draw a coordinate axis */

    if (DRAWAXIS) drawAxes(5);
    if (DRAWSPHERE) drawSphere();

    glFlush();
    glutSwapBuffers();

}

void onAxis(int msg)
{
    switch (msg) {
        case 1:
            DRAWAXIS = 1; 
            break;
        case 2:
            DRAWAXIS = 0; 
            break;
    }
    glutPostRedisplay();
}

void onSphere(int msg)
{
    switch (msg) {
        case 1:
            DRAWSPHERE = 1; 
            break;
        case 2:
            DRAWSPHERE = 0; 
            break;
    }
    glutPostRedisplay();
}

void doNothing(int msg)
{
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{

    // Menu types are of type integer
    int menu, axis, sphere;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (500, 500); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape);

    // Let's add a menu item //
    axis = glutCreateMenu(onAxis);
    glutAddMenuEntry("On", 1);
    glutAddMenuEntry("Off", 2);

    // Let's add another menu item
    sphere = glutCreateMenu(onSphere);
    glutAddMenuEntry("On", 1);
    glutAddMenuEntry("Off", 2);
 
    // And now create the menu 
    menu = glutCreateMenu(doNothing);
    glutAddSubMenu("Axes", axis);
    glutAddSubMenu("Sphere", sphere);

    glutAttachMenu(GLUT_MIDDLE_BUTTON);


    glutMainLoop();
    return 0;
}
