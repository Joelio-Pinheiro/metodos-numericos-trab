#include "../headers/rocket.h"
#include "../headers/numethods.h"
#include "../headers/exceptions.h"
#include "../headers/datastructures.h"

#include <iostream>
#include <math.h>
#include <iomanip>

double Rocket::f(double x){
    return this->a * x - x * std::log(x);
}

double Rocket::df(double x){
    return this->a - (std::log(x) + 1);
}

Rocket::Rocket(double a, double precision, int id){
    this->id = id;
    this->a = a;
    this->precision = precision;

    signRuleInterval = calculateSignRuleInterval(this->a);
    newtonRaphsonIV = calculateNewtonRaphsonInitialValue(this->a);

    calculateRoots();
}

Interval Rocket::calculateSignRuleInterval(double a){
    return Interval(std::exp(a - 1), std::exp(a + 1));
}

double Rocket::calculateNewtonRaphsonInitialValue(double a){
    return (std::exp(a - 1) + std::exp(a + 1))/2.0;
}

int Rocket::getId() {return this->id;}
std::string Rocket::getLastError() {return this->errorMsg;}

void Rocket::calculateRoots(){
    using namespace NumericalMethods;

    try{
        this->bisectionRoot     = bisection     ([this](double x) -> double {return this->f(x);}, signRuleInterval.getA(), signRuleInterval.getB(), precision, this->errorBisection);
        this->falsePositionRoot = falsePos      ([this](double x) -> double {return this->f(x);}, signRuleInterval.getA(), signRuleInterval.getB(), precision, precision, this->errorFalsePosition);
        this->newtonRaphsonRoot = newtonRaphson ([this](double x) -> double {return this->f(x);}, [this](double x) -> double {return this->df(x);}, newtonRaphsonIV, precision, precision, this->errorNewtonRaphson);
    }
    catch(NumericExceptions::ConvergenceFailure e) {errorMsg = e.getErrorMsg();}
    catch(NumericExceptions::InvalidInterval e) {errorMsg = e.getErrorMsg();}
}

void Rocket::displayResults(){
    //sufixo d: foguete explode (dangerous)
    //sufixo s: foguete não explode (safe)

    char bExplosion   =   (bisectionRoot > 2.0) ? 'd' : 's';
    char fpExplosion  =   (falsePositionRoot > 2.0) ? 'd' : 's';
    char nrExplosion  =   (newtonRaphsonRoot > 2.0) ? 'd' : 's';

    std::cout << std::fixed << std::setprecision(Rocket::ROOT_PRECISION);
    std::cout << std::setw(5) << id << std::setw(14) << a
                << std::setw(10) << bisectionRoot << bExplosion << std::setw(11) << std::setprecision(2) << errorBisection << "%"
                << std::setw(5) << std::setprecision(2) << "[" << signRuleInterval.getA() << ", " << signRuleInterval.getB() << "]"
                << std::setw(15) << std::setprecision(Rocket::ROOT_PRECISION) << falsePositionRoot << fpExplosion << std::setw(12) << std::setprecision(2) << errorFalsePosition << "%"
                << std::setw(5) << std::setprecision(2) << "[" << signRuleInterval.getA() << ", " << signRuleInterval.getB() << "]"
                << std::setw(13) << std::setprecision(Rocket::ROOT_PRECISION) << newtonRaphsonRoot << nrExplosion << std::setw(13) << std::setprecision(2) << errorNewtonRaphson << "%"
                << std::setw(15) << newtonRaphsonIV
                << "\n";
}