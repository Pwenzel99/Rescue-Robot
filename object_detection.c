/*
 * object_detection.c: Handles object detection and determining what is classified as an object
 *
 *  Created on: Apr 7, 2019
 *      Author: ryanjl9
 */

#include <object_detection.h>

/*
 * OBJECTS: Max number of objects detected
 */
#define OBJECTS 20

/*
 * POINTS: Max number of points taken
 */
#define POINTS 90

/*
 * PI: Constant value of pi
 */
#define PI 3.14159265

//Define two structs to hold data
struct object objects[OBJECTS];
struct point points[POINTS];

//Stores number of seen objects
int numObjects;

/**
 * getObjects: This method processes data from points into objects
 */
void getObjects(){
	int i;
	int count = 0;
	int inObject = 0;
	//struct object cur;

	for(i = 0; i < POINTS; i++){
		if(points[i].distSonar <= 50 && points[i].distIR <= 50){
			if(inObject){
				objects[count].data[(objects[count].rSize)++] = points[i];
			}
			if(!inObject){ //create object
				inObject = 1;
				objects[count].rSize = 0;

				objects[count].data[(objects[count].rSize)++] = points[i];
			}
		}

		if(!(points[i].distSonar <= 50 && points[i].distIR <= 50)){
			if(inObject){//add point to object
				inObject = 0;
				getLinearWidth(&objects[count]);
				if(objects[count].rSize > 1) count++;
			}
		}
	}

	//if we reach the end and are still in an object
	if(inObject){//leave object
		inObject = 0;
		getLinearWidth(&objects[count]);
		count++;
	}

	numObjects = count;
}

/**
 * getLinearWidth: Thie method uses trig to calculate the linear width of an object
 *
 * @param obj: Array of objects detected
 */
void getLinearWidth(struct object* obj){
	struct object o = *obj;
	double a = o.data[0].distSonar;
	double b = o.data[o.rSize-1].distSonar;
	int angle = o.rSize;

	//a^2 + b^2 - 2abcos(angle)
	obj -> lWidth = sqrt((pow(a,2.0) + pow(b,2.0)) - 2.0*a*b*cos((angle*PI)/180.0));
}

/**
 * sweep: This method is used to get a list of all objects
 */
void sweep(){
	timer_waitMillis(500);
	int i;

	for(i = 0; i < 179; i+=2){
		move_servo(i);
		ping_trigger();
		timer_waitMillis(1);

		points[i/2].distIR = ir_getDistance();
		points[i/2].distSonar = sonar_getDistance();
		points[i/2].degree = i;
	}

	getObjects();
}




















