#ifndef PROTOTYPES
#define PROTOTYPES

#include "structs.h"
/*
void init(void);
void drawAxes(int );
void defineHouse( struct face* );
void drawHouse( struct face* );
void display(void);
void updateRotations(void);
void reshape (int , int );
void mouse(int, int, int, int);
void keyboard( unsigned char , int , int  );
*/


void init(void);
void drawAxes(int length);
void defineHouse(face *faces);
void drawHouse(struct face *faces);
void drawHelloWorld();
void display(void);
void reshape (int w, int h);
void updateRotations(void);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char key, int x, int y);
void keyboardSpecial(int key, int x, int y);
void createMenus();
void drawText();
void changeProjection();


#endif
