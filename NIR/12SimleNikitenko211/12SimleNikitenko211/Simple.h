#pragma once
#include <cmath>

double Simple(double X, double Y) {

	double itog = (cos(X) + sin(Y)) / log(X + Y);	
	return(double) itog;

}