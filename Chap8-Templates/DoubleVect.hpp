#include <cassert>

template<unsigned int DIM> class DoubleVector
{
private:
    double mData[DIM];
public:
    double& operator[](int index) // overload de []
    {
        assert(index < DIM);
        assert(index > -1);
        return(mData[index]);
    }
};