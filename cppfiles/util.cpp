#include "../headers/util.h"

double Util::getSign(double value){
    if (value < 0) return -1.0;
    else if (value > 0) return 1.0;
    else return 0.0;
}

double Util::abs(double value){
    if (value < 0) return value * -1.0;
    else return value;
}