#ifndef DEFINE_HOUSE
#define DEFINE_HOUSE

#include "structs.h"


void defineHouse( face *faces )
{
	faces[0].point[0].x = -1.0;  // Bottom
	faces[0].point[0].y = -1.0;
	faces[0].point[0].z =  0.0;
	faces[0].point[0].w =  1.0;
	faces[0].point[1].x = -1.0;
	faces[0].point[1].y =  1.0;
	faces[0].point[1].z =  0.0;
	faces[0].point[1].w =  1.0;
	faces[0].point[2].x =  1.0;
	faces[0].point[2].y =  1.0;
	faces[0].point[2].z =  0.0;
	faces[0].point[2].w =  1.0;
	faces[0].point[3].x =  1.0;
	faces[0].point[3].y = -1.0;
	faces[0].point[3].z =  0.0;
	faces[0].point[3].w =  1.0;

	faces[1].point[0].x = -1.0;  // Left Side
	faces[1].point[0].y = -1.0;
	faces[1].point[0].z =  0.0;
	faces[1].point[0].w =  1.0;
	faces[1].point[1].x = -1.0;
	faces[1].point[1].y = -1.0;
	faces[1].point[1].z =  1.5;
	faces[1].point[1].w =  1.0;
	faces[1].point[2].x =  1.0;
	faces[1].point[2].y = -1.0;
	faces[1].point[2].z =  1.5;
	faces[1].point[2].w =  1.0;
	faces[1].point[3].x =  1.0;
	faces[1].point[3].y = -1.0;
	faces[1].point[3].z =  0.0;
	faces[1].point[3].w =  1.0;

	faces[2].point[0].x = -1.0;  // Right Side
	faces[2].point[0].y =  1.0;
	faces[2].point[0].z =  0.0;
	faces[2].point[0].w =  1.0;
	faces[2].point[1].x = -1.0;
	faces[2].point[1].y =  1.0;
	faces[2].point[1].z =  1.5;
	faces[2].point[1].w =  1.0;
	faces[2].point[2].x =  1.0;
	faces[2].point[2].y =  1.0;
	faces[2].point[2].z =  1.5;
	faces[2].point[2].w =  1.0;
	faces[2].point[3].x =  1.0;
	faces[2].point[3].y =  1.0;
	faces[2].point[3].z =  0.0;
	faces[2].point[3].w =  1.0;

	faces[3].point[0].x = -1.0;  // Back Side
	faces[3].point[0].y = -1.0;
	faces[3].point[0].z =  0.0;
	faces[3].point[0].w =  1.0;
	faces[3].point[1].x = -1.0;
	faces[3].point[1].y = -1.0;
	faces[3].point[1].z =  1.5;
	faces[3].point[1].w =  1.0;
	faces[3].point[2].x = -1.0;
	faces[3].point[2].y =  1.0;
	faces[3].point[2].z =  1.5;
	faces[3].point[2].w =  1.0;
	faces[3].point[3].x = -1.0;
	faces[3].point[3].y =  1.0;
	faces[3].point[3].z =  0.0;
	faces[3].point[3].w =  1.0;

	faces[4].point[0].x =  1.0;  // Front Side
	faces[4].point[0].y = -1.0;
	faces[4].point[0].z =  0.0;
	faces[4].point[0].w =  1.0;
	faces[4].point[1].x =  1.0;
	faces[4].point[1].y = -1.0;
	faces[4].point[1].z =  1.5;
	faces[4].point[1].w =  1.0;
	faces[4].point[2].x =  1.0;
	faces[4].point[2].y =  1.0;
	faces[4].point[2].z =  1.5;
	faces[4].point[2].w =  1.0;
	faces[4].point[3].x =  1.0;
	faces[4].point[3].y =  1.0;
	faces[4].point[3].z =  0.0;
	faces[4].point[3].w =  1.0;

	faces[5].point[0].x =  0.0;  // Roof1
	faces[5].point[0].y = -1.0;
	faces[5].point[0].z =  2.5;
	faces[5].point[0].w =  1.0;
	faces[5].point[1].x =  0.0;
	faces[5].point[1].y =  1.0;
	faces[5].point[1].z =  2.5;
	faces[5].point[1].w =  1.0;
	faces[5].point[2].x =  1.0;
	faces[5].point[2].y =  1.0;
	faces[5].point[2].z =  1.5;
	faces[5].point[2].w =  1.0;
	faces[5].point[3].x =  1.0;
	faces[5].point[3].y = -1.0;
	faces[5].point[3].z =  1.5;
	faces[5].point[3].w =  1.0;

	faces[6].point[0].x = -1.0;  // Roof2
	faces[6].point[0].y = -1.0;
	faces[6].point[0].z =  1.5;
	faces[6].point[0].w =  1.0;
	faces[6].point[1].x = -1.0;
	faces[6].point[1].y =  1.0;
	faces[6].point[1].z =  1.5;
	faces[6].point[1].w =  1.0;
	faces[6].point[2].x =  0.0;
	faces[6].point[2].y =  1.0;
	faces[6].point[2].z =  2.5;
	faces[6].point[2].w =  1.0;
	faces[6].point[3].x =  0.0;
	faces[6].point[3].y = -1.0;
	faces[6].point[3].z =  2.5;
	faces[6].point[3].w =  1.0;


// Define the colors
//
	faces[0].color.red   = 1.0;
	faces[0].color.green = 1.0;
	faces[0].color.blue  = 1.0;

	faces[1].color.red   = 0.0;
	faces[1].color.green = 1.0;
	faces[1].color.blue  = 0.0;

	faces[2].color.red   = 1.0;
	faces[2].color.green = 1.0;
	faces[2].color.blue  = 0.0;

	faces[3].color.red   = 1.0;
	faces[3].color.green = 0.0;
	faces[3].color.blue  = 0.0;

	faces[4].color.red   = 1.0;
	faces[4].color.green = 0.0;
	faces[4].color.blue  = 1.0;

	faces[5].color.red   = 0.0;
	faces[5].color.green = 0.0;
	faces[5].color.blue  = 1.0;

	faces[6].color.red   = 0.0;
	faces[6].color.green = 1.0;
	faces[6].color.blue  = 1.0;

}

#endif
