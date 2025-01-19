#include "../headers/util.h"
#include <iostream>
#include <string>

double Util::getSign(double value){
    if (value < 0) return -1.0;
    else if (value > 0) return 1.0;
    else return 0.0;
}

double Util::abs(double value){
    if (value < 0) return value * -1.0;
    else return value;
}
void Util::clearConsole(){
#if _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int Util::getPositiveInt(const std::string &prompt){
    int value = 0;
    while (true)
    {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);
        try
        {
            size_t pos;
            value = std::stoi(input, &pos);
            if (pos == input.length() && value > 0)
                break;
        }
        catch (...) {
            clearConsole();
            std::cout << "Entrada invalida. Por favor, insira um numero inteiro positivo.\n";
        }
    }
    return value;
}

double Util::getPositiveDouble(const std::string &prompt){
    double value = 0.0;
    while (true)
    {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);
        try
        {
            size_t pos;
            value = std::stod(input, &pos);
            if (pos == input.length() && value > 0)
                break;
        }
        catch (...)
        {
            clearConsole();
            std::cout << "Entrada invalida. Por favor, insira um numero decimal positivo.\n";
        }
    }
    return value;
}