#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

class Interval{
    private:
        double a;
        double b;

    public:
        Interval();
        Interval(double a, double b);

        double getA();
        double getB();
};

#endif