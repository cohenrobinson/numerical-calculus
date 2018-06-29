// demonstration of integration libraries
// author: Cohen Robinson
// date: 27/06/18

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "integration.h"

double f1(double x);

int main()
{
  FILE *fOut;

	fOut=fopen("num_integration.txt","w");

  double analyticResult = PI * PI / 12.0;

  int N;
	int i;
	double x_left = 1 * pow(10, -20);
	double x_right = 1;
  function f1;
	//print to file
	fprintf(fOut, "%-5s %-15s %-15s %-15s\n","Loop","Trapezoidal","Simpson","Newton-Cotes");
	//print to file
	for(i = 1; i < 12 ; i++) {
		//define n_partitions
		N = 3 * i;
		//print to file
		fprintf(fOut,"%-5d %-.13f %-.13f %.13f\n", i+1, analyticResult-trapezoidal(x_left, x_right, f1, N),analyticResult-simpson(x_left, x_right, f1, N),analyticResult-newtoncotes(x_left, x_right, f1, N));
		//print each error to the terminal
		printf("\nError in Trapezoidal in %d loop: %f",i+1,analyticResult-trapezoidal(x_left, x_right, f1, N));

		printf("\nError in Simpson in %d loop: %f",i+1,analyticResult-simpson(x_left, x_right, f1, N));

		printf("\nError in Newton-Cotes (Degree 3) in %d loop: %f", i+1 , analyticResult-newtoncotes(x_left, x_right, f1, N));

	}

  getchar();
  return 0;
}

// test function
double f1(double x)
{
  if (x == 0.0){
    return 1.0;
  }
  return log(1 + x) / x;      // natural log
}
