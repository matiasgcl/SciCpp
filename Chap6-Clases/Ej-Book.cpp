// Ejemplo uso clase Libro

#include <iostream>
#include "Book.hpp"

int main(int argc, char* argv[])
{
    Book buena_lectura;
    buena_lectura.author = "C S Lewis";
    buena_lectura.title = "The silver chair";
    buena_lectura.publisher = "Geoffrey Bles";
    buena_lectura.price = 699;
    buena_lectura.format = "paperback";
    buena_lectura.SetYearOfPublication(1953);

    Book otro_libro(buena_lectura);

    Book libro_extra("Los hermanos Karamazov");

    std::cout << buena_lectura.title << std::endl;
    std::cout << otro_libro.title << std::endl;
    std::cout << libro_extra.title << std::endl;
    
    return 0;
}