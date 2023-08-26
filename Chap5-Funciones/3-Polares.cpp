// Codigo de ejemplo para entender la manipulación de punteros para modificar valores
// pb clásico: en C++ solo se puede devolver un valor, y si quiero modificar más de una cosa?

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <cassert>

void PolarARectangular(double r, double theta, double* pRe, double* pIm);
// alternativamente double& Re, double& Im
int main(int argc, char* argv[])
{
    assert(argc==3);
    double r = atof(argv[1]);
    double theta = atof(argv[2]);
    double x, y;
    PolarARectangular(r, theta, &x, &y);
    std::cout << "z=rexp(itheta) con r: " << r << " theta: " << theta << "\n"; 
    std::cout << "Re: " << x << "\n";
    std::cout << "Im: " << y << "\n";
    return 0;
}

void PolarARectangular(double r, double theta, double* pRe, double* pIm)
// alternativamente double& Re, double& Im
{
    *pRe = r*cos(theta);
    *pIm = r*sin(theta);
    // alternativamente: Re = ..., Im = ...
}