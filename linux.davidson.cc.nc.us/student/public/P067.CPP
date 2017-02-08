// Show some mathematical functions available from cmath
#include <iostream.h> // For cout
#include <math.h>    // For fabs, ceil, floor, and pow

int main()
{
  double x = -2.1;

  cout << "fabs(x) :      " << fabs(x)      << endl
       << "ceil(x) :      " << ceil(x)      << endl
       << "floor(x) :     " << floor(x)     << endl
       << "pow(x, 2.0) :  " << pow(x, 2.0)  << endl;

  return 0;
}