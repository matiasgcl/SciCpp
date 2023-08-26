#include <iostream>
#include <cassert>

double ProdEscalar(double* a, double* b, int size);

int main(int argc, char* argv[])
{
    int n = 10;
    double* x = new double[n];
    double* y = new double[n];
    std::cout << sizeof(x) << std::endl;
    for(int i=0;i<n;i++){
        x[i] = (i+1)/2.0;
        y[i] = (i+1)*(i+1)/200.0;
    }
    double prod_esc = ProdEscalar(x,y,n);
    std::cout << "<x,y> = " << prod_esc << std::endl;
    delete[] x;
    delete[] y;

    return 0;
}

double ProdEscalar(double* a, double* b, int size){
    assert((sizeof(a)) == (sizeof(b)));
    double res = 0.0;
    for (int i=0; i<size; i++){
        res += a[i]*b[i];
    }
    return res;
}