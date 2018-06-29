// demo of the differentiation libraries
// author: Cohen Robinson
// date: 27/06/18

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "differentiation.h"

int main() {
  //define file
  FILE *fOut;

  fOut = fopen("comparemethods.txt","w");

  int n = 4;
  int i;
  double x = PI/3;
  double h;
  function sin;

  //prints out titles
  fprintf(fOut,"%-7s %-7s %-7s %-7s\n","n","FDM","BDM","CDM");

  //loops through all values of n
  for(i=1;i<=n;i++){
  	h=pow(10,-i);
  	fprintf(fOut,"%-5d %-5.5f %-5.5f %-5.5f\n", i, forward_difference(sin, x, h), backward_difference(sin, x, h), central_difference(sin, x, h));
  }

  //Extention
  //sin x is the second derivative of -sinx
  fprintf(fOut,"\n%-6s %-6s %-6s\n","n","2NDFX","cos(x)");
  i=1;
  for ( i = 1; i <= n; i++){
  	h = pow(10,-i);
  	fprintf(fOut,"%-5d %-5.5f %5.5f\n", i, second_derivative(sin, x, h), -sin(x));
  }
	//will converge to the correct value as n increases

  return 0;
}
