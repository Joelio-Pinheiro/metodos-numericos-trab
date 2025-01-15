#ifndef NUMETHODS_H
#define NUMETHODS_H

namespace NumericalMethods{
    double bisection(double (*f)(double), double a, double b, double e);
    double falsePos(double (*f)(double), double a, double b, double e1, double e2);
    double newtonRaphson(double (*f)(double), double (*df)(double), double approx, double e1, double e2);
};

#endif