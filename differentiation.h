// libraries for use with numerical differentiation
// author: Cohen Robinson
// date: 27/06/18

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

// define function
typedef double (function)(double);

// define central_difference method
double central_difference(function f, double x, double h)
{
	return (f(x + h) - f(x - h)) / (2 * h);
}

// define backward difference method
double backward_difference(function f, double x, double h)
{
  return (f(x) - f(x - h)) / h;
}

// define forward difference method
double forward_difference(function f, double x, double h)
{
  return (f(x + h) - f(x)) / h;
}

// define factorial function
double factorial(int n)
{
  double fac = 1.;
  for (int i = 1; i <= n; i++){
    fac *= i;
  }
  return fac;
}

//second derivative - EXTENSION
double second_derivative(function f, double x, double h)
{
	return (f(x + h) + f(x - h) - 2 * f(x))/(pow(h,2));
}
