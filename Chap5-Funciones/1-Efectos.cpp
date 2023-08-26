#include <iostream>

void SinEfecto(double x); // x es copiado en SinEfecto, si lo modifico eso ocurre en su scope
void ConEfecto(double& x); // &x -> la referencia, puedo modificarlo y se conserva en su globalidad

int main(int argc, char* argv[]){
    double x = 2.0;
    SinEfecto(x);
    std::cout << "Sin efecto: " << x << "\n"; // 2.0
    ConEfecto(x);
    std::cout << "Con efecto: " << x << "\n"; // 2.0
}

void SinEfecto(double x){
    x += 1.0;
}

void ConEfecto(double& x){
    x += 1.0;
}