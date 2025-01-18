#ifndef UTIL_H
#define UTIL_H
#include <string>

namespace Util{
    double getSign(double value);
    double abs(double value);
    int getPositiveInt(const std::string& prompt);
    double getPositiveDouble(const std::string& prompt);
    void clearConsole();
};

#endif