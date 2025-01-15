#include <iostream>
#include <limits>
#include <vector>
#include <math.h>

#include "headers/numethods.h"
#include <iomanip>

class Rocket
{
private:
    double a;                  // Parâmetro de ajuste
    double precision;          // Precisão
    double bisectionRoot;      // Raiz calculada pelo método da Bisseção
    double falsePositionRoot;  // Raiz calculada pelo método da Posição Falsa
    double newtonRaphsonRoot;  // Raiz calculada pelo método de Newton-Raphson
    double errorBisection;     // Erro do método da Bisseção
    double errorFalsePosition; // Erro do método da Posição Falsa
    double errorNewtonRaphson; // Erro do método de Newton-Raphson

    static double f(double x)
    {
        return x - x*std::log(x);
    }

    static double df(double x)
    {
        return 1.0 - std::log(x);
    }

public:
    Rocket(double a, double precision)
        : a(a), precision(precision),
          bisectionRoot(0), falsePositionRoot(0), newtonRaphsonRoot(0),
          errorBisection(0), errorFalsePosition(0), errorNewtonRaphson(0) {}

    void calculateRoots()
    {
        using namespace NumericalMethods;
        std::cout << "1" << '\n';
        this->bisectionRoot = bisection(f, 2, 3, precision);
        std::cout << "2" << '\n';
        this->falsePositionRoot = falsePos(f, 2, 3, precision, precision);
        std::cout << "3" << '\n';
        //this->newtonRaphsonRoot = newtonRaphson(f, df, 2, precision, precision);
        std::cout << "4" << '\n';

        this->errorBisection = 0.000f;
        this->errorFalsePosition = 0.000f;
        this->errorNewtonRaphson = 0.000f;
    }
     void displayResults(int id) const
    {
        std::cout << std::fixed << std::setprecision(6);
        std::cout << std::setw(5) << id << std::setw(15) << a
                  << std::setw(12) << bisectionRoot << std::setw(12) << errorBisection
                  << std::setw(15) << falsePositionRoot << std::setw(10) << errorFalsePosition
                  << std::setw(15) << newtonRaphsonRoot << std::setw(10) << errorNewtonRaphson
                  << "\n";
    }
};


double f(double x)
{
    return x - x*std::log10(x);
}

double df(double x)
{
    return 1 - std::log10(x);
}

int main()
{
    using namespace NumericalMethods;
    int num_foguetes;
    double precision;
    std::vector<Rocket> foguetes;

    printf("----------- Sistema de Cálculo de Deslocamento de Foguetes -----------\n");
    printf("Digite o número de foguetes: ");
    std::cin >> num_foguetes;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    printf("Digite a precisão desejada (e): ");
    std::cin >> precision;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (size_t i = 0; i < num_foguetes; i++)
    {
        double a = 0;
        std::cout << "Digite o valor de a para o foguete " << i + 1 << ": ";
        std::cin >> a;
        Rocket foguete = Rocket(a, precision);

        foguetes.push_back(foguete);
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "aa" << '\n';
    for (Rocket &foguete : foguetes)
    {
          std::cout << "cc" << '\n';
        foguete.calculateRoots();
    }
    std::cout << "bb" << '\n';
    std::cout << "\nQuadro de Resposta:\n";
    std::cout << std::setw(6) << "ID" << std::setw(10) << "A"
              << std::setw(15) << "Bissecao" << std::setw(10) << "Erro"
              << std::setw(17) << "Posicao Falsa" << std::setw(10) << "Erro"
              << std::setw(16) << "Newton-Raphson" << std::setw(10) << "Erro"
              << "\n";
    int id = 1;
    for (const Rocket &foguete : foguetes)
    {
        foguete.displayResults(id++);
    }
    return 0;
}