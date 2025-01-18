#ifndef ROCKET_H
#define ROCKET_H

class Rocket {
public:
    Rocket(double a, double precision);
    void calculateRoots();
    void displayResults(int id) const;

private:
    double a;                  // Parâmetro de ajuste
    double precision;          // Precisão
    double bisectionRoot;      // Raiz calculada pelo método da Bisseção
    double falsePositionRoot;  // Raiz calculada pelo método da Posição Falsa
    double newtonRaphsonRoot;  // Raiz calculada pelo método de Newton-Raphson
    double errorBisection;     // Erro do método da Bisseção
    double errorFalsePosition; // Erro do método da Posição Falsa
    double errorNewtonRaphson; // Erro do método de Newton-Raphson

    static double f(double x);
    static double df(double x);
};

#endif 