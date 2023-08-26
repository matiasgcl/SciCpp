#ifndef BOOKHEADERDEF
#define BOOKHEADERDEF

#include <string>

class Book
{
public:
    Book(); // sobre-escribiendo el constructor original (es igual)
    Book(std::string bookTitle); // constructor adicional
    Book(const Book& otherBook); // copy-constructor, const para asegurarse que otherBook no será modificado
    std::string author, title, publisher, format;
    int price; 
    void SetYearOfPublication(int year);
    int GetYearOfPublication() const; // const pues es un getter, nos aseguramos que no modificará nada
private:
    int mYearOfPublication;
}; // no olvidar!

#endif