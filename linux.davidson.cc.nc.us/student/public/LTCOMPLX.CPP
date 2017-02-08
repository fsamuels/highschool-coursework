//--------------------------------------------------------------------
// Implements class complex
//--------------------------------------------------------------------
#include "ltcomplx.h"  // for separate compilation

complex::complex()
{
  my_real = 0.0;
  my_imag = 0.0;
}

complex::complex(double initReal)
{
  my_real = initReal;
  my_imag = 0.0;
}

complex::complex(double initReal, double initImag)
{
  my_real = initReal;
  my_imag = initImag;
}

double complex::real() const
{
  return my_real;
}

double complex::imag() const
{
  return my_imag;
}

// Implement complex arithmetic operations as global functions. 
// Conversions allows for many possible operand types with one 
// function. For example c + 1, 1 + c, c + 1.0, 1.0 + c
complex operator + (complex left, complex right)
{ // Complex addition 
  // (a + bi) + (c + di)  =  (a + c) + (b + d)i 
  double tempReal = left.my_real + right.my_real; // a+c, the real part
  double tempImag = left.my_imag + right.my_imag; // b+d, imaginary part
  complex temp(tempReal, tempImag); 
  return temp; 
} 

complex operator / (complex left, complex right)
{ // Complex division:
  //                     a * c + b * d    b * c - a * d
  // (a+b*i)/(c+d*i)  =  ------------- +  ------------- * i
  //                       c*c + d*d        c*c + d*d

  double den;      // c squared + d squared (denominator)
  double nuR, nuI; // The numerators: R for Real, I for Imaginary

  den = pow(right.my_real, 2) + pow(right.my_imag, 2);
  nuR = (left.my_real * right.my_real) + (left.my_imag * right.my_imag);
  nuI = (left.my_imag * right.my_real) - (left.my_real * right.my_imag);

  // Create and return a new complex number:
  complex temp(nuR / den, nuI / den);
  return temp;
}

ostream & operator << (ostream & left, complex right)
{
  left << "(" << right.my_real << ", " << right.my_imag << ")";
  return left;
}

istream & operator >> (istream & left, complex & right)
{
  double x, y;
  left >> x >> y;
  right = complex(x, y);
  return left;
}