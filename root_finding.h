// libraries for use in root finding
// author: Cohen Robinson
// date: 27/06/18

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double grad( double (*function)(double), double x){
  double sep = 0.00001; // delta x
  double y2 = function(x+sep);
  double y1 = function(x-sep);
  double grad = (y2-y1)/(2*sep);
  return grad;
}

// function that runs the newton_raphison method of root finding
double newton_raph( double (*function)(double), double x1, double x2, double xacc){

  double xold = x1;   // begin at x1 and move to x2
  double xnew = xold; function(xold)/grad(function, xold);  // calc first root
  int counter = 1;

  while (fabs(xnew-xold) >= fabs(xacc)){

    xold = xnew;
    xnew = xold - function(xold)/grad(function, xold);
    counter++;
  }
  if (xnew >= x1 && xnew <= x2){
    printf("The number of iterations in the Newton-Raphson method is: %d\n", counter);
    return xnew;
  }
  else{
    if (x1 < x2){
      return rtnewt( function, x1+0.01, x2, xacc);
    }
    else{
      printf("Error in newton_raph: Failed to find a root in the given range!\n");
      return 0;
    }
  }
}
