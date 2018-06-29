# numerical-calculus
Libraries for use in differentiation, integration and root finding. 
Can be used for basic calculus techniques in small intervals.

## Numerical Differentiation
Libraries for differentiation include:
- Central difference method
- Forward difference method
- Backward difference method
- Second derivative calculation

There is an included demo executable that when run will use the example of a sine function at PI/3

## Numerical Integration
Libraries for integration include:
- Trapezoidal method
- Simpsons Rule
- Newton-Cotes (Degree 3) Formulae

Another demo is included that demonstrates integrating a function log(1+x)/x over a small interval.
(Something to note that these formulae are only accurate over small intervals, especially the Trapezoidal method - as you will see from the demo).

## Root Finding
Libraries for root finding include:
- Newton-Raphson Method
- False Position

Included is root_demo_exec which demonstrates the accuracy of False Position in comparison to the Newton-Raphson Method of finding the roots of y(x) = x^2 - 5.
