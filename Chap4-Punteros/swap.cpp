#include <iostream> 

void swap(int* p_x, int* p_y); // hacer swap usando punteros

int main(){
    int i = 4;
    int j = 14;
    swap(&i, &j);

    std::cout << i << std::endl;
    std::cout << j << std::endl;
}

void swap(int* p_x, int* p_y){
    int tmp = *p_x; // valor intermedio, de-referencio p_x
    *p_x = *p_y; // intercambio i->j 
    *p_y = tmp;  // j -> i usando el valor intermedio guardado anteriormente
}

// alternativa: void swap(int& i, int& j) 