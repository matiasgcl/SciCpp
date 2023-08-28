// Ejemplo de uso de tipo Vector

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(int argc, char* argv[])
{
    std::vector<std::string> destinations;
    destinations.reserve(6);
    destinations.push_back("Paris");
    destinations.push_back("New York");
    destinations.push_back("Singapore");
    std::cout << "Length of vector is " << destinations.size() << "\n";
    std::cout << "Entries of vector are\n";

    // for clásico
    for (int i=0; i<3; i++)
    {
        std::cout << destinations[i] << " (for clásico)\n";
    }
    
    // for usando 'iterator' (puede reemplazarse por auto)
    std::vector<std::string>::const_iterator c;
    for (c=destinations.begin(); c!=destinations.end(); c++)
    // puedo omitir la definicion como iterador de c, y usar (c++11 o más)
    // for (auto c=destinations.begin(); c!=destinations.end(); c++)
    {
        std::cout << *c << " (for usando iterator)\n";
    }
    
    // insercion usando insert (definiendo lugar) o push_back (al final)
    destinations.insert(destinations.begin(), "Sydney");
    destinations.insert(destinations.begin()+1, "Moscow");
    destinations.push_back("Frankfurt");
    std::cout << "Length of vector is " << destinations.size() << " (post insert)\n";
    std::cout << "Entries of vector are\n";
    for (c=destinations.begin(); c!=destinations.end(); c++)
    {
        std::cout << *c << "\n";
    }

    // uso método erase
    destinations.erase(destinations.begin()+3,destinations.end());
    std::cout << "Length of vector is " << destinations.size() << " (post erase)\n";
    std::cout << "Entries of vector are\n";
    
    for (c=destinations.begin(); c!=destinations.end(); c++)
    {
        std::cout << *c << "\n";
    }
    
    // uso sort (requiere #include <algorithm>)
    sort(destinations.begin(), destinations.end());
    std::cout << "Length of vector is " << destinations.size() << "\n";
    std::cout << "Entries of vector are (post sort)\n";
    for (c=destinations.begin(); c!=destinations.end(); c++)
    {
        std::cout << *c << "\n";
    }

    return 0;
}