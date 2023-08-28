#include <iostream>
#include "DoubleVect.hpp"

// tambien testeo templated class
template<class T> T Maximum(T n1, T n2);

int main(int argc, char* argv[])
{
    std::cout << Maximum<int>(4,-1) << "\n";
    std::cout << Maximum<double>(4.3/3.0,-1.0/12.0) << "\n";

    DoubleVector<5> v;
    v[0] = 1;
    //v[5] = 2.0;
    return 0;
}

template<class T> T Maximum(T n1, T n2)
{
    T result;
    if(n1>n2)
    {
        result = n1;
    }
    else
    {
        result = n2;
    }
    return result;
}

