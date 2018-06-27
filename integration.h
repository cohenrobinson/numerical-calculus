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
		sum += 2 * f(x);
    x += h;
	}

	return h * sum / 2;
}

// simpsons rule for integration assumes that f is a polynomial
double simpson(double left_bound, double right_bound, function f, int iterations)
{
  double x = left_bound;     // start at left_bound
	double h = (right_bound - left_bound) / iterations;    // step_size

  // sum over iteractions
  double sum = f(0) + f(iterations);    // m of 1
  int m = 4;    // to add constant to terms
  for (int i = 1; i < iterations; i++){
    sum += m * f(x);
    if (m == 4){
      m = 2;
    }
    else{
      m = 4;
    }
    x += h;
  }

  return h * sum / 3;
}

// newton cotes formulae assumes
// also to degree of 3
double newtoncotes(double left_bound, double right_bound, function f, int iterations)
{
	if (iterations <= 2){ // This insures that there is a minimum of 3 partitions.
		printf("ERROR: Please choose iterations greater than 2!\n");
    exit(0);
	}
	else {
		if (iterations % 3 != 0){
			printf("ERROR: Please choose iterations divisible by 3!\n");
      exit(0);
		}
	}

	unsigned int k = iterations / 3;

	double x = left_bound;
	double h = (right_bound - left_bound) / iterations;
	double current_sum = 0.0;
	int i;
	for (i = 0; i < k; i++){
		current_sum += 3 * h * (f( x + (3 * i)*h ) + 3.0 * f( x + (3 * i + 1)*h ) + 3.0 * f( x + (3 * i + 2)* h) + f( x + (3 * i + 3)*h)) / 8.0;
	}

	return current_sum; // All partitions have been summed.
}
