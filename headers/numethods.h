#ifndef NUMETHODS_H
#define NUMETHODS_H

#include <functional>

namespace NumericalMethods{
    double bisection(std::function<double(double)> f, double a, double b, double e, double &er);
    double falsePos(std::function<double(double)> f, double a, double b, double e1, double e2, double &er);
    double newtonRaphson(std::function<double(double)> f, std::function<double(double)> df, double approx, double e1, double e2, double &er);
};

#endif