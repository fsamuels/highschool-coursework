// File name: test7h.cpp
#include <iostream>
// using namespace std;
#include "compfun"
#include "baccount"

int main()
{ // Test drive the modified bankAccount class
  decimals(cout, 2);  
  bankAccount anAcct("Larry", 200.00);
  anAcct.withdraw(-20.0);              // anAcct is not modified
  anAcct.deposit(-20.0);               // anAcct is not modified
  cout << anAcct.balance() << endl;    // Output: 200.00
  anAcct.withdraw(201.01);             // anAcct is modified
  cout << anAcct.balance() << endl;    // Output: 0.00
  cout << anAcct.overdrawn() << endl;  // Output: 1.01
  anAcct.withdraw(300.00);
  cout << anAcct.balance() << endl;    // Output: 0.00
  cout << anAcct.overdrawn() << endl;  // Output: 301.01

  causeApause();
  return 0;
}
