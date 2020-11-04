#ifndef PROTOTYPES
#define PROTOTYPES

#include "structs.h"

void init(void);
void drawAxes(int );
void defineBox( struct face* );
void drawBox( struct face* );
void display(void);
void updateRotations(void);
void reshape (int , int );

/*
void init(void)
void drawAxes(int length)
void defineBox( box *face )
void drawBox( struct box *face )
void display(void)
void reshape (int w, int h)
*/
#endif
