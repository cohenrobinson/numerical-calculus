// demo for root_finding libraries
// author: Cohen Robinson
// date: 27/06/18

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "root_finding.h"

// function to be demonstrated
double xsqminfive( double x){
  return x * x - 5;
}

int main(){
  double xacc = 0.1;  // required precision
  double trueroot = sqrt(5);  // actual value for root
  double nr_root = newton_raph(xsqminfive, 0, 3, xacc);
  double fp_root = false_pos(xsqminfive, 0, 3, 0.001);

  printf("Function: y(x) = x^2 - 5\n");
  printf("Expected root: x = sqrt(5)\n"); // negative root outside of 0 - 3 bound
  printf("Newton-Raphson: %f\n", nr_root);
  printf("False-Position: %f\n", fp_root);
  printf("Error in Newton-Raphson: %f\n", fabs(trueroot-nr_root));
  printf("Error in False Position: %f\n", fabs(trueroot-fp_root));

  return 0;
}
