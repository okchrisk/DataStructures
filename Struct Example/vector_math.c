#include <stdio.h>
#include <stdlib.h>
#include "vector_math.h"

int main(int argc, char *argv[]) {

	// initialize variables
	Vec3d vec1;
	Vec3d vec2;
	Vec3d vec3;
	Vec3d vec4;
	Line line1;
	
	vec3dSet(&vec1, -2, 1, 10); // sets vec1
	vec3dPrint(&vec1);
	
	vec3dSet(&vec2, 3.6, -7, 0.2); // sets vec 2
	vec3dPrint(&vec2);
	
	vec3dAdd(&vec1, &vec2, &vec3); // sets vec3 from SUM(vectors) from vec1 and vec2
	vec3dPrint(&vec3);
	
	vec3dScalarMul(&vec3, 0.5, &vec4); // multiplying vec by a static amount, storing in vec4
	vec3dPrint(&vec4);
	
	lineSet(&line1, &vec1, &vec4); // assigning values to Line struct with 2 Point typedefs
	linePrint(&line1);
	
	// Dynamically allocating memory for 2 Vec3d vars
	// dma = Dynamic Memory Allocation; variable name helps explain what it represents
	Vec3d* dmaVec1 = malloc(sizeof(Vec3d));
	Vec3d* dmaVec2 = malloc(sizeof(Vec3d));
	
	vec3dSet(dmaVec1, -2, 1, 10);
	vec3dPrint(dmaVec1);
	
	vec3dScalarMul(dmaVec1, -1.75, dmaVec2); // storing scalar multiplication result into dmaVec2
	vec3dPrint(dmaVec2);
		
	// used to free up allocated memory before program closes	
	free(dmaVec1);
	free(dmaVec2);

}// end of main method

// Function Implementation

void vec3dSet(Vec3d* vec, double x, double y, double z){
	// sets the property fields of the struct: x, y, z
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

void vec3dPrint(const Vec3d* vec){
	// grabs the fields of the struct and prints them individually
	printf ("(%g, %g, %g)\n", vec->x, vec->y, vec->z);
}

void vec3dAdd(const Vec3d* src1, const Vec3d* src2, Vec3d* dst){
	// sets the 3rd struct argument to the summation of each respective field. ie. x3 = x1 + x2
	dst->x = src1->x + src2->x;
	dst->y = src1->y + src2->y;
	dst->z = src1->z + src2->z;
}

// multiplying each field by the value, storing in another variable
void vec3dScalarMul(const Vec3d* src, double a, Vec3d* dst){
	dst->x = src->x * a;
	dst->y = src->y * a;
	dst->z = src->z * a;
}

// since the line is composed of 2 points, which are composed of 3 values- we set each individual value
void lineSet(Line* line, const Point* start, const Point* end){
	line->point1.x = start->x;
	line->point1.y = start->y;
	line->point1.z = start->z;
	line->point2.x = end->x;
	line->point2.y = end->y;
	line->point2.z = end->z;
}

// printing each value (3) of each Point (2) for a total of 6 values
void linePrint(const Line* line){
	printf("(%g, %g, %g) - (%g, %g, %g)\n", 	line->point1.x,line->point1.y,line->point1.z,
											line->point2.x,line->point2.y,line->point2.z);
}
