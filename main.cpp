#include <iostream>

#include "headers/numethods.h"

double f(double x){
    return x*x*x + 2*x*x + x + 20;
}

double df(double x){
    return 3*x*x + 4*x + 1;
}

int main(){
    using namespace NumericalMethods;

    printf("Bisection Root: %.4f\n", bisection(f, -5.0, 5.0, 0.000001));
    printf("False Position Root: %.4f\n", falsePos(f, -5, 5, 0.000001, 0.000001));
    printf("Newton Raphson Root: %.4f\n", newtonRaphson(f, df, -3.0, 0.000001, 0.000001));

    return 0;
}