// Newton-Raphson para ejemplificar el uso de punteros de funciones
// f(x)=0 ? x_{n+1} = x_n - f(x_n)/f'(x_n)

#include <cmath>
#include <iostream>

double RaizNewton(double (*pFunc)(double), double (*pFuncDeriv)(double), double x)
{
    double step;
    do
    {
        step = (*pFunc)(x)/(*pFuncDeriv)(x);
        x -= step;
    } while (fabs(step) > 1.0e-5);
    // std::cout << "Terminado! con |step|=" << fabs(step) << std::endl;
    return x;
}

double Sqrt100(double x)
{
    return sqrt(x)-100.0;
}

double Sqrt100Deriv(double x)
{
    return 1.0/(2.0*sqrt(x));
}

double Cube10(double x)
{
    return x*x*x-10.0;
}

double Cube10Deriv(double x)
{
    return 3*x*x;
}

int main(int argc, char* argv[])
{
    double ResSqrt = RaizNewton(Sqrt100, Sqrt100Deriv,1.0);
    double ResCube = RaizNewton(Cube10, Cube10Deriv,1.0);
    std::cout << "La solución de sqrt(x)=100, con x0 1.0 es " << ResSqrt << "\n";
    std::cout << "y satisface sqrt(x*)=" << sqrt(ResSqrt) << std::endl;
    std::cout << "La solución de x^3=10, con x0 1.0 es " << ResCube << "\n";
    std::cout << "y satisface f(x*)=" << ResCube*ResCube*ResCube << std::endl;
    return 0;
}