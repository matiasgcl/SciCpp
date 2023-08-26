#include <iostream>

double** AsignarMemoriaMatriz(int numFilas, int numCols);
void LiberarMemoriaMatriz(int numFilas, double** matriz);
void ImprimirMatriz(unsigned int numFilas, unsigned int numCols, double** matriz);

int main(int argc, char* argv[]){
    double** A;
    A = AsignarMemoriaMatriz(5,3);
    A[0][1] = 2.0;
    A[4][2] = 4.0;
    ImprimirMatriz(5,3,A);
    LiberarMemoriaMatriz(5,A);
    ImprimirMatriz(5,3,A); // Segmentation fault, pues la memoria fue liberada! (A no está asignado)
    return 0;
}

// Fn para asignar memoria dinámicamente a una matriz
double** AsignarMemoriaMatriz(int numFilas, int numCols)
{
    double** matriz;
    matriz = new double* [numFilas];
    for(int i=0; i<numFilas; i++)
    {
        matriz[i] = new double [numCols];
    }
    return matriz;
}

// Fn para liberar memoria utilizada por una matriz
void LiberarMemoriaMatriz(int numFilas, double** matriz)
{
    for(int i=0; i<numFilas; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void ImprimirMatriz(unsigned int numFilas, unsigned int numCols, double** matriz)
{
    for(int i=0; i<numFilas; i++)
    {
        for(int j=0; j<numCols; j++)
        {
            std::cout << matriz[i][j] << std::endl;
        }
    }
    
}