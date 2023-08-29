#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

class Vector
{
private:
   double* mData; // datos (notar que es puntero)
   int mSize; // tamaño
public:
   Vector(const Vector& otherVector); // copy-const
   Vector(int size); // const
   ~Vector(); // destructor
   int GetSize() const;
   double& operator[](int i); // indexación desde 0
   // lectura desde 0
   double Read(int i) const;
   double& operator()(int i); // indexación desde 1 (con paréntesis!)
   
   Vector& operator=(const Vector& otherVector); // asignación
   Vector operator+() const; // unario +
   Vector operator-() const; // unario -
   Vector operator+(const Vector& v1) const; // binario +
   Vector operator-(const Vector& v1) const; // binario -
   // mult por escalar
   Vector operator*(double a) const;
   // norma p
   double CalculateNorm(int p=2) const;
   // fn largo (friend! no método)
   friend int length(const Vector& v);
};

// 'signature' prototipo de length (friend!)
int length(const Vector& v);

#endif
