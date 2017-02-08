// Illustrates a vector of programmer-defined objects
#include <iostream.h>
#include "vector"   // For the vector<CLASS> class
#include "baccount" // For the bankAccount class
#include "compfun"  // For decimals(cout, 2);

int main()
{
  int j, n;
  vector <bankAccount> account(100);

  // Initialize the first n elements of account
  n = 4;
  account[0] = bankAccount("Hall", 0.00);
  account[1] = bankAccount("Small", 100.00);
  account[2] = bankAccount("Ewall", 200.00);
  account[3] = bankAccount("Westphall", 300.00);
  // assert: The first n elements of account are initialized

  double assets = 0.0;
  // Accumulate balance of n bankAccount objects stored in account
  for(j = 0; j < n; j++)
  {
    assets += account[j].balance();
  }
  decimals(cout, 2);
  cout << "Assets: " << assets << endl;

  return 0;
}
