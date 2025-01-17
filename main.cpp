#include <iostream>
#include <limits>
#include <vector>
#include "headers/rocket.h"
#include <iomanip>

int main()
{
    int num_foguetes;
    double precision;
    std::vector<Rocket> foguetes;

    printf("----------- Sistema de Calculo de Deslocamento de Foguetes -----------\n");
    printf("Digite o numero de foguetes: ");
    std::cin >> num_foguetes;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    printf("Digite a precisao desejada (e): ");
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
    for (Rocket &foguete : foguetes)
    {
        foguete.calculateRoots();
    }
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