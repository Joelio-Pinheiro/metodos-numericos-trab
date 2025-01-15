#include "../headers/numethods.h"
#include "../headers/exceptions.h"
#include "../headers/util.h"

double NumericalMethods::bisection(double (*f)(double), double a, double b, double e){
    if (f(a) * f(b) > 0) throw NumericExceptions::InvalidInterval("Regra dos sinais não atendida!");
    if (a > b) throw NumericExceptions::InvalidInterval("O valor de a deve ser menor ou igual a b!");
    
    //Para evitar o lançamento de mais erros, o valor de tolerância é corrigido, caso um valor negativo seja passado
    e = Util::abs(e);

    if (b - a < e) return (b - a)/2.0;

    double a_sign = Util::getSign(a);

    //Como o método sempre converge, esse loop não é infinito!
    while(true){
        double x = (a + b)/2.0;

        if (a_sign * f(x) > 0) a = x;
        else b = x;

        if (b - a < e) return x;
    }
}

double NumericalMethods::falsePos(double (*f)(double), double a, double b, double e1, double e2){
    if (f(a) * f(b) > 0) throw NumericExceptions::InvalidInterval("Regra dos sinais não atendida!");
    if (a > b) throw NumericExceptions::InvalidInterval("O valor de a deve ser menor ou igual a b!");

    e1 = Util::abs(e1);
    e2 = Util::abs(e2);

    if (b - a < e1) return (b - a)/2.0;

    if (Util::abs(f(a)) < e2) return a;
    if (Util::abs(f(b)) < e2) return b;

    double a_sign = Util::getSign(f(a));

    //Mesma situação da bisseção, convergência é garantida, então o loop não é infinito!
    while (true){
        double fa = f(a);
        double fb = f(b);

        double x = (a*fb - b*fa)/(fb - fa);
   
        double fx = f(x);

        if (Util::abs(fx) < e2) return x;

        if (a_sign * fx > 0) a = x;
        else b = x;

        if (b - a < e1) return x;
    }
}

double NumericalMethods::newtonRaphson(double (*f)(double), double (*df)(double), double approx, double e1, double e2){
    const static int MAX_ITERATIONS = 20;

    e1 = Util::abs(e1);
    e2 = Util::abs(e2);

    if (Util::abs(f(approx)) < e1) return approx;

    int i = 0; //Contador de iterações

    double x0 = approx;
    double x1;

    //Como a convergência nesse método nem sempre é garantida, um limite arbitrário de iterações é colocado
    while(true){
        if (i == MAX_ITERATIONS) throw NumericExceptions::ConvergenceFailure("O método não conseguiu convergir em tempo hábil!");

        x1 = x0 - (f(x0)/df(x0));

        if (Util::abs(f(x1)) < e1) return x1;
        else if (Util::abs(x1 - x0) < e2) return x1;

        x0 = x1;

        ++i; 
    }
}
