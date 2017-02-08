// Initialize two bankAccount objects and send some messages
#include <iostream.h> // For cout
#include "baccount" // For the bankAccount class

int main()
{
  bankAccount anAcct("Hall", 100.00); // Construct a bankAccount
  bankAccount anotherAcct("Fuller", 987.65);
  anAcct.deposit(133.33); // Send a deposit message to anAcct
  anotherAcct.withdraw(250.00);
  cout << anAcct.name() << ": " << anAcct.balance() << endl;
  cout << anotherAcct.name() << ": " << anotherAcct.balance() << endl;
  
  return 0;
}