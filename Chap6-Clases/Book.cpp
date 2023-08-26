#include "Book.hpp"
#include <cassert>

// Sobre-escritura del constructor por defecto
Book::Book()
{
    author = "no especificado";
    title = "no especificado";
    publisher = "no especificado";
    format = "no especificado";
}

// Sobre-escritura del copy-const (es exactamente lo que hace el del sistema)
Book::Book(const Book& otherBook)
{
    author = otherBook.author;
    title = otherBook.title;
    publisher = otherBook.publisher;
    format = otherBook.format;
    price = otherBook.price;
    mYearOfPublication = otherBook.GetYearOfPublication(); // es privado! debo usar el getter
}

// Constructor especializado
Book::Book(std::string bookTitle)
{
    title = bookTitle;
}

// Implementando los métodos
void Book::SetYearOfPublication(int year)
{
    assert((year>1440)&&(year<2023));
    mYearOfPublication = year;
}

int Book::GetYearOfPublication() const
{
    return mYearOfPublication;
}