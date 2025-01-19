#include "../headers/numethods.h"
#include "../headers/exceptions.h"
#include "../headers/util.h"

double NumericalMethods::bisection(std::function<double(double)> f, double a, double b, double e, double &er){
    if (f(a) * f(b) > 0) throw NumericExceptions::InvalidInterval("Regra dos sinais nao atendida!");
    if (a > b) throw NumericExceptions::InvalidInterval("O valor de a deve ser menor ou igual a b!");
    
    //Para evitar o lançamento de mais erros, o valor de tolerância é corrigido, caso um valor negativo seja passado
    e = Util::abs(e);

    if (b - a < e) return (b - a)/2.0;

    double a_sign = Util::getSign(a);

    double x;
    double x_old = a; //x_old é usado para cálculo de erro

    //Como o método sempre converge, esse loop não é infinito!
    while(true){
        x = (a + b)/2.0;

        if (a_sign * f(x) > 0) a = x;
        else b = x;

        er = Util::abs((x - x_old)/x) * 100.0;

        if (b - a < e) return x;

        x_old = x;
    }
}

double NumericalMethods::falsePos(std::function<double(double)> f, double a, double b, double e1, double e2, double &er){
    if (f(a) * f(b) > 0) throw NumericExceptions::InvalidInterval("Regra dos sinais nao atendida!");
    if (a > b) throw NumericExceptions::InvalidInterval("O valor de a deve ser menor ou igual a b!");

    e1 = Util::abs(e1);
    e2 = Util::abs(e2);

    if (b - a < e1) return (b - a)/2.0;

    if (Util::abs(f(a)) < e2) return a;
    if (Util::abs(f(b)) < e2) return b;

    double a_sign = Util::getSign(f(a));

    double x;
    double x_old = a;

    //Mesma situação da bisseção, convergência é garantida, então o loop não é infinito!
    while (true){
        double fa = f(a);
        double fb = f(b);

        x = (a*fb - b*fa)/(fb - fa);
   
        double fx = f(x);

        er = Util::abs((x - x_old)/x) * 100.0;

        if (Util::abs(fx) < e2) return x;

        if (a_sign * fx > 0) a = x;
        else b = x;

        if (b - a < e1) return x;

        x_old = x;
    }
}

double NumericalMethods::newtonRaphson(std::function<double(double)> f, std::function<double(double)> df, double approx, double e1, double e2, double &er){
    const static int MAX_ITERATIONS = 20;

    e1 = Util::abs(e1);
    e2 = Util::abs(e2);

    if (Util::abs(f(approx)) < e1) return approx;

    int i = 0; //Contador de iterações

    double x0 = approx;
    double x1;

    //Como a convergência nesse método nem sempre é garantida, um limite arbitrário de iterações é colocado
    while(true){
        if (i == MAX_ITERATIONS) throw NumericExceptions::ConvergenceFailure("O metodo nao conseguiu convergir em tempo habil!");

        x1 = x0 - (f(x0)/df(x0));

        er = Util::abs((x1 - x0)/x1) * 100.0;

        if (Util::abs(f(x1)) < e1) return x1;
        else if (Util::abs(x1 - x0) < e2) return x1;

        x0 = x1;

        ++i; 
    }
}
