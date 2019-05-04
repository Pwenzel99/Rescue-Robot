/*
 * object_detection.h - Header file for object detection file
 *
 *  Created on: Apr 7, 2019
 *      Author: ryanjl9
 */

#ifndef OBJECT_DETECTION_H_
#define OBJECT_DETECTION_H_

#include <stdio.h>
#include <math.h>

/*
 * point: A struct which holds our two distances and the angle which the point is at
 */
struct point{
	int degree;
	double distIR;
	double distSonar;
};

/*
 * object: Holds total number of points which makes up an object and gets it's radial
 * 		   width and linear width
 */
struct object{
	int rSize;

	double lWidth;

	struct point data[20];
};

extern struct object objects[];
extern struct point points[];

extern int numObjects;

void getObjects();
void getLinearWidth(struct object* obj);
void sweep();

#endif /* OBJECT_DETECTION_H_ */
