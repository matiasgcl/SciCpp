#ifndef FORWARDSOLVERDEF
#define FORWARDSOLVERDEF

#include "AbstractOdeSolver.hpp"

class ForwardSolver: public AbstractOdeSolver
{
public:
    double RightHandSide(double y, double t);
    double SolveEquation();
};

#endif