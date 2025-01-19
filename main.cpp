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

    int id = 1;
    for (size_t i = 0; i < num_foguetes; i++)
    {
        double a = Util::getPositiveDouble("Digite o valor de a para o foguete " + std::to_string(i + 1) + ": ");
        Rocket foguete = Rocket(a, precision, id++);
        foguetes.push_back(foguete);
    }

    Util::clearConsole();

    std::cout << '\n' << "****************************************************************************************************************************";

    std::cout << std::setprecision(16) << std::defaultfloat << '\n' << "Tolerancia: " << precision;

    std::cout << "\nQuadro de Resposta:\n";
    std::cout << std::setw(6) << "ID" << std::setw(10) << "A"
              << std::setw(15) << "Bissecao" << std::setw(10) << "Erro" << std::setw(15) << "Intervalo"
              << std::setw(20) << "Posicao Falsa" << std::setw(10) << "Erro" << std::setw(15) << "Intervalo"
              << std::setw(20) << "Newton-Raphson" << std::setw(10) << "Erro" << std::setw(20) << "Valor Inicial"
              << "\n";

    for (Rocket &foguete : foguetes)
    {
        if (foguete.getLastError() == "") foguete.displayResults();
        else std::cout << std::setw(50) << "Foguete " << foguete.getId() << ": " << foguete.getLastError() << '\n';
    }

    std::cout << '\n' << "sufixo s: foguete seguro" << "         " << "sufixo d: foguete nao seguro (explode)";

    std::cout << '\n' << "****************************************************************************************************************************";
    return 0;
}