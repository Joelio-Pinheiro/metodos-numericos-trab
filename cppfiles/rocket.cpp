#include "../headers/rocket.h"
#include "../headers/numethods.h"

#include <iostream>
#include <math.h>
#include <iomanip>

double Rocket::f(double x)
{
    return x - x * std::log(x);
}

double Rocket::df(double x)
{
    return 1.0 - std::log(x);
}

Rocket::Rocket(double a, double precision)
    : a(a), precision(precision),
      bisectionRoot(0), falsePositionRoot(0), newtonRaphsonRoot(0),
      errorBisection(0), errorFalsePosition(0), errorNewtonRaphson(0) {}

void Rocket::calculateRoots()
{
    using namespace NumericalMethods;
    this->bisectionRoot = bisection(f, 2, 3, precision);
    this->falsePositionRoot = falsePos(f, 2, 3, precision, precision);
    // this->newtonRaphsonRoot = newtonRaphson(f, df, 2, precision, precision);

    this->errorBisection = 0.000f;
    this->errorFalsePosition = 0.000f;
    this->errorNewtonRaphson = 0.000f;
}
 void Rocket::displayResults(int id) const
    {
        std::cout << std::fixed << std::setprecision(6);
        std::cout << std::setw(5) << id << std::setw(15) << a
                  << std::setw(12) << bisectionRoot << std::setw(12) << errorBisection
                  << std::setw(13) << falsePositionRoot << std::setw(12) << errorFalsePosition
                  << std::setw(15) << newtonRaphsonRoot << std::setw(13) << errorNewtonRaphson
                  << "\n";
    }