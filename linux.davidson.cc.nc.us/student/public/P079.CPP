#include "compfun"  // For decimals(cout, 2)
#include <iostream.h> // For cout

int main()
{
  double money = 100.00;

  cout << money << endl;
  decimals(cout, 2);
  cout << "Just called decimals(cout, 2)" << endl;
  cout << money << endl;
  
  return 0;
}
