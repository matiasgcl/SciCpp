#include "ComplexNumber.hpp"
#include <cmath>

// Constructores
ComplexNumber::ComplexNumber() // default 
{
    mRe = 0.0;
    mIm = 0.0;
}

ComplexNumber::ComplexNumber(double x, double y)
{
    mRe = x;
    mIm = y;
}

ComplexNumber::ComplexNumber(double x)
{
    mRe = x;
    mIm = 0.0;
}


ComplexNumber::ComplexNumber(const ComplexNumber& w)
{
    mRe = w.GetRealPart();
    mIm = w.GetImaginaryPart();
}


double ComplexNumber::Modulus() const
{
    return sqrt(mRe*mRe + mIm*mIm);
}

double ComplexNumber::Argument() const
{
    return atan2(mIm, mRe);
}

// Usamos De-Moivre para la potencia natural:
// z^n=(rexp(it))^n = r^n(cos nt + i sen nt) = r^n cos nt + i r^n sen nt
ComplexNumber ComplexNumber::Power(double n) const 
{
    double modulus = Modulus(); // ojo con los contextos en este tipo de operaciones, estoy dentro de la clase aquí.
    if(modulus==0){
        ComplexNumber z(0);
        return z;
    }
    if(n==0){
        ComplexNumber z(1);
        return z;
    }
    double argument = Argument();
    double mod_of_result = pow(modulus, n);
    double arg_of_result = argument*n;
    double real_part = mod_of_result*cos(arg_of_result);
    double imag_part = mod_of_result*sin(arg_of_result);
    ComplexNumber z(real_part, imag_part);
    return z;
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z) 
{
    mRe = z.mRe;
    mIm = z.mIm;
    return *this; // uso de this, ojo
}

// resta unaria, i.e.: que significa '-x' (w=-x)
ComplexNumber ComplexNumber::operator-() const 
{
    ComplexNumber w;
    w.mRe = -mRe;
    w.mIm = -mIm;
    return w;
}

// suma binaria, i.e. w = x + z
ComplexNumber ComplexNumber::operator+(const ComplexNumber& z) const
{
    ComplexNumber w;
    w.mRe = mRe + z.mRe;
    w.mIm = mIm + z.mIm;
    return w;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) const
{
    ComplexNumber w;
    w.mRe = mRe - z.mRe;
    w.mIm = mIm - z.mIm;
    return w;
}

// Overload de << (esto es interesante), así manejo el output via std::cout
std::ostream& operator<<(std::ostream& output, const ComplexNumber& z) 
{
    // formato a+bi o a-bi (depende de b, obviamente)
    output << "(" << z.mRe << " ";
    if (z.mIm >= 0.0)
    {
        output << "+ " << z.mIm << "i)";
    }
    else
    {
        output << "- " << -z.mIm << "i)";
    }
    return output;
}

double ComplexNumber::GetRealPart() const
{
    return mRe;
}

double ComplexNumber::GetImaginaryPart() const
{
    return mIm;
}

double RealPart(const ComplexNumber& z)
{
    return z.GetRealPart();
}

double ImaginaryPart(const ComplexNumber& z)
{
    return z.GetImaginaryPart();
}

ComplexNumber ComplexNumber::Conjugate() const
{
    ComplexNumber w(mRe,-mIm);
    return w;
}

void ComplexNumber::SetToConjugate()
{
    mIm = -mIm;
}


