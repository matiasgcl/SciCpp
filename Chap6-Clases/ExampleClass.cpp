#include "ExampleClass.hpp"

// constructor
ExampleClass::ExampleClass(double member1, double member2)
{
    mMemberVar1 = member1;
    mMemberVar2 = member2;
}

// GetMin es un método que es parte de la clase
double ExampleClass::GetMinimum() const
{
    if (mMemberVar1<mMemberVar2) 
    { 
        return mMemberVar1; 
    }
    else
    {
        return mMemberVar2;
    }
}

double GetMaximum(const ExampleClass& eg_class)
{
    if (eg_class.mMemberVar1<eg_class.mMemberVar2) 
    { 
        return eg_class.mMemberVar2;
    } 
    else
    {
        return eg_class.mMemberVar1;
    } 
}