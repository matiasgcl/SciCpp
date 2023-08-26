#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF

#include <iostream>

class ComplexNumber
{
private:
    double mRe;
    double mIm;
public:
    // constructores
    ComplexNumber();
    ComplexNumber(double x, double y);
    ComplexNumber(double x);
    ComplexNumber(const ComplexNumber& w); // copy-constructor, const para asegurarse que w no será modificado

    double Modulus() const;
    double Argument() const;
    ComplexNumber Conjugate() const;
    double GetRealPart() const;
    double GetImaginaryPart() const;
    void SetToConjugate();
    friend double RealPart(const ComplexNumber& z);
    friend double ImaginaryPart(const ComplexNumber& z);
    ComplexNumber Power(double n) const;
    ComplexNumber& operator=(const ComplexNumber& z); // asignacion
    ComplexNumber operator-() const; // resta unaria
    ComplexNumber operator+(const ComplexNumber& z) const; // suma y resta binaria
    ComplexNumber operator-(const ComplexNumber& z) const;
    friend std::ostream& operator<<(std::ostream& output, const ComplexNumber& z); 
    /* overloading del output stream <<, para tener control del formato de salida; 
    se usa friend porque << no debe considerarse parte de la clase! */
};

#endif