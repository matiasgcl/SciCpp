#include <iostream>
#include "ExampleClass.hpp"

int main(int argc, char* argv[])
{
    ExampleClass example(2.0, 3.0);
    std::cout << "Minimum value = " << example.GetMinimum() << "\n";
    std::cout << "Max value = " << GetMaximum(example) << "\n";
}