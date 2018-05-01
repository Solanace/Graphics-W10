#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gmath.h"
#include "matrix.h"
#include "ml6.h"

//lighting functions
color get_lighting(double *normal, double *view, color alight, double light[2][3], double *areflect, double *dreflect, double *sreflect) {
	color i;
	i.red = 0;
	i.green = 0;
	i.blue = 0;
	limit_color(&i);
	return i;
}

color calculate_ambient(color alight, double *areflect) {
	color a;
	return a;
}

color calculate_diffuse(double light[2][3], double *dreflect, double *normal) {
	color d;
	return d;
}

color calculate_specular(double light[2][3], double *sreflect, double *view, double *normal) {
	color s;
	return s;
}


//limit each component of c to a max of 255
void limit_color(color * c) {
	if (c->red < 0) c->red = 0;
	if (c->green < 0) c->green = 0;
	if (c->blue < 0) c->blue = 0;

	if (c->red > 255) c->red = 255;
	if (c->green > 255) c->green = 255;
	if (c->blue > 255) c->blue = 255;
}

//vector functions
//normalize vector, should modify the parameter
void normalize(double *vector) {
	double magnitude = sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2));
	vector[0] /= magnitude;
	vector[1] /= magnitude;
	vector[2] /= magnitude;
}

//Return the dot porduct of a . b
double dot_product(double *a, double *b) {
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

double *calculate_normal(struct matrix *polygons, int i) {

  double A[3];
  double B[3];
  double *N = (double *)malloc(3 * sizeof(double));

  A[0] = polygons->m[0][i+1] - polygons->m[0][i];
  A[1] = polygons->m[1][i+1] - polygons->m[1][i];
  A[2] = polygons->m[2][i+1] - polygons->m[2][i];

  B[0] = polygons->m[0][i+2] - polygons->m[0][i];
  B[1] = polygons->m[1][i+2] - polygons->m[1][i];
  B[2] = polygons->m[2][i+2] - polygons->m[2][i];

  N[0] = A[1] * B[2] - A[2] * B[1];
  N[1] = A[2] * B[0] - A[0] * B[2];
  N[2] = A[0] * B[1] - A[1] * B[0];

  return N;
}
