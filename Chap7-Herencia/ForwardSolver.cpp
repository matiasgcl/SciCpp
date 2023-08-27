#include "ForwardSolver.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

double ForwardSolver::RightHandSide(double y, double t)
{
    return 1.0+t;
}

double ForwardSolver::SolveEquation()
{
    assert(stepSize!=0);
    assert(initialTime<finalTime);
    double N = (finalTime-initialTime)/stepSize;
    assert(initialTime + floor(N)*stepSize == finalTime);
    double* t = new double[N+1];
    double* y = new double[N+1];
    y[0] = initialValue;
    t[0] = initialTime;
    for(int i=1; i<N+1; i++)
    {
        t[i] = t[i-1]+stepSize;
        y[i] = y[i-1]+stepSize*RightHandSide(y[i-1],t[i-1]);
        double exacto = 0.5*(t[i]*t[i]+2*t[i]+4.0);
        std::cout << "Euler: " << y[i] << ", " << "exacto: " << exacto << std::endl;
    }
    delete[] t;
    delete[] y;
}

int main(int argc, char* argv[])
{
    ForwardSolver test;
    test.SetStepSize(0.01);
    test.SetTimeInterval(0.0,1.0);
    test.SetInitialValue(2.0);
    test.SolveEquation();
    return 0;
}