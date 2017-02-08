//--------------------------------------------------------------------
// Defines and implements class complex
//--------------------------------------------------------------------
#ifndef LTCOMPLEX_H
#define LTCOMPLEX_H
#include <iostream>   // for class ostream and class istream
#include <cmath>

class complex {
public:
  // The three constructors allow initializations like this
  // complex a;             // real = 0.0  imaginary = 0.0
  // complex b(1.0);        // real = 1.0  imaginary = 0.0
  // complex c(2.5, 3.5);   // real = 2.5  imaginary = 3.5
  complex();
  //POST: Complex object set to default (0.0, 0.0)

  complex(double initReal);
  //POST: Complex object set to (initReal, 0.0)

  complex(double initReal, double initImag);
  //POST: Complex object set to (initReal,0) or (initReal,initImag)

  // Accessing functions
  double real()  const;
  // POST: The real part of the complex object is returned

  double imag()  const;
  // POST: The imaginary part of the complex object is returned

//--operator functions  
  friend complex   operator +  (complex left, complex right);
  friend complex   operator /  (complex left, complex right);
  friend ostream & operator << (ostream & left, complex right);
  friend istream & operator >> (istream & left, complex & right);

private:
  double my_real;
  double my_imag;
};

#endif  // #ifndef LTCOMPLEX_H
