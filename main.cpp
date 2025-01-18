#include <iostream>
#include <limits>
#include <vector>
#include "headers/rocket.h"
#include "headers/util.h"
#include <iomanip>

int main()
{
    int num_foguetes;
    double precision;
    std::vector<Rocket> foguetes;

    printf("----------- Sistema de Calculo de Deslocamento de Foguetes -----------\n");
    printf("Este programa calcula as raizes das equacoes usando metodos numericos.\n");
    printf("---------------------------------------------------------------------\n\n");

    num_foguetes = Util::getPositiveInt("Digite o numero de foguetes: ");

    precision = Util::getPositiveDouble("Digite a precisao desejada (e): ");

    for (size_t i = 0; i < num_foguetes; i++)
    {
        double a = Util::getPositiveDouble("Digite o valor de a para o foguete " + std::to_string(i + 1) + ": ");
        Rocket foguete = Rocket(a, precision);
        foguetes.push_back(foguete);
    }
    for (Rocket &foguete : foguetes)
    {
        foguete.calculateRoots();
    }

    Util::clearConsole();
    printf("Precisao: %.f", precision);
    std::cout << "\nQuadro de Resposta:\n";
    std::cout << std::setw(6) << "ID" << std::setw(10) << "A"
              << std::setw(15) << "Bissecao" << std::setw(10) << "Erro"
              << std::setw(17) << "Posicao Falsa" << std::setw(10) << "Erro"
              << std::setw(17) << "Newton-Raphson" << std::setw(11) << "Erro"
              << "\n";
    int id = 1;
    for (const Rocket &foguete : foguetes)
    {
        foguete.displayResults(id++);
    }
    return 0;
}