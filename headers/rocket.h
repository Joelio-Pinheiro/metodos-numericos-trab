#ifndef ROCKET_H
#define ROCKET_H

#include "../headers/datastructures.h"

#include <string>

class Rocket {
    public:
        static const unsigned int ROOT_PRECISION = 4;

        Rocket(double a, double precision, int id);

        int getId();

        void displayResults();
    
        double f(double x);
        double df(double x);

        std::string getLastError();
    private:
        std::string errorMsg = "";

        int id;

        double a;                  // Parâmetro de ajuste
        double precision;          // Precisão
        double bisectionRoot;      // Raiz calculada pelo método da Bisseção
        double falsePositionRoot;  // Raiz calculada pelo método da Posição Falsa
        double newtonRaphsonRoot;  // Raiz calculada pelo método de Newton-Raphson
        double errorBisection;     // Erro do método da Bisseção
        double errorFalsePosition; // Erro do método da Posição Falsa
        double errorNewtonRaphson; // Erro do método de Newton-Raphson

        Interval signRuleInterval;
        double newtonRaphsonIV;

        static Interval calculateSignRuleInterval(double a);
        static double calculateNewtonRaphsonInitialValue(double a);

        void calculateRoots();
};

#endif 