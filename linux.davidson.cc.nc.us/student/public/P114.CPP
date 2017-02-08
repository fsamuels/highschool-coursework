#include <iostream.h> // For cout
#include "baccount" // For the bankAccount class

int main()
{
  bankAccount b1("B. Kreible", 0.00);
  bankAccount b2("N. Li", 500.00);
  
  b1.deposit(222.22);
  b1.withdraw(20.00);
  b2.deposit(55.55);
  b2.withdraw(10.00);
  cout << b1.name() << ": " << b1.balance() << endl;
  cout << b2.name() << ": " << b2.balance() << endl;

  return 0;
}