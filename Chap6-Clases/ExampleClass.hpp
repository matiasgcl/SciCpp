#ifndef EXAMPLECLASSDEF
#define EXAMPLECLASSDEF

class ExampleClass
{
private:
    double mMemberVar1;
    double mMemberVar2;

public:
    ExampleClass(double member1, double member2); // constructor
    double GetMinimum() const;
    friend double GetMaximum(const ExampleClass& ex_class); // function amiga, NO ES PARTE DE LA CLASE.
};

#endif