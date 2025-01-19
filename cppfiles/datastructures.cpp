#include "../headers/datastructures.h"

Interval::Interval(double a, double b){
    this->a = a;
    this->b = b;
}
Interval::Interval() {this->a = 0; this->b = 1;}

double Interval::getA() {return this->a;}
double Interval::getB() {return this->b;}