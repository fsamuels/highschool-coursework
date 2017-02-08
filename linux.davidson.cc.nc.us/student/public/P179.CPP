// Test drive the new decimals function
#include "compfun"  // For decimals(cout, 2)
#include <iostream.h> // For cout

int main()
{
  double x = 234.57;

  cout << "Default appearance: " << x << endl;
  decimals(cout, 1);
  cout << x << endl;
  
  decimals(cout, 2);
  cout << x << endl;
  
  decimals(cout, 3);
  cout << x << endl;

  return 0;
}
