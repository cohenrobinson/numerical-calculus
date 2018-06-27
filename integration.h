// libraries for various numerical integration methods
// author: Cohen Robinson
// date: 27/06/18

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535897932384

typedef double (function)(double);

// defintion for trapizoidal integration
// assumes linear across region
double trapezoidal(double left_bound, double right_bound, function f, int iterations)
{
  // define variables
	double x = left_bound;     // start at left_bound
	double h = (right_bound - left_bound) / iterations;    // step_size

	// sum over iterations
	double sum = f(0) + f(iterations);
	for (int i = 1; i < iterations; i++){
		sum += 2 * f(i * h);
	}

	return h * sum / 2;
}

// simpsons rule for integration assumes that f is a polynomial
double simpson(double left_bound, double right_bound, function f, int iterations)
{
  double x = left_bound;     // start at left_bound
	double h = (right_bound - left_bound) / iterations;    // step_size

  // sum over n_interactions
  double sum = f(0) + f(iterations);
  int m = 4;
  for (int i = 1; i < iterations; i++){
    sum += m * f(i * h);
    if (m == 4){
      m = 2;
    }
    else{
      m = 4;
    }
  }

  return h * sum / 3;
}

// newton cotes formulae assumes 
