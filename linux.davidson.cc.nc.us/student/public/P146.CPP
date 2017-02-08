#include <iostream.h> // For cout
#include <math.h> // For pow

double f(double x)
{ // post: Return 2 * x * x - 1
  double result;
  result = 2 * pow(x, 2) - 1.0;
  return result;
}

int main()
{
  // 0. Declare objects
  double x, y;
  
  // 1. Input
  cout << "Input x: ";
  cin >> x;

  // 2. Process (occurs in function f)
  y = f(x);
  
  // 3. Output
  cout << "f(" << x << ") = " << y << endl;

  return 0;
}