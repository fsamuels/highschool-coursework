#include <iostream.h>
#include "compfun"

double factorial (int n)
{ // pre: n >= 0 and n is not too large
  double result = 1;
  for(int j = 2; j <= n; j++)
  {
    result = j * result;
  }
  return result;
}

int main()
{
  cout << factorial(0) << endl; // 1
  cout << factorial(1) << endl; // 1
  cout << factorial(2) << endl; // 2
  cout << factorial(3) << endl; // 6
  cout << factorial(4) << endl; // 24
  decimals(cout, 1);
  cout << factorial(12) << endl; // 479001600

  return 0;
}
