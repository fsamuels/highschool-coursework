// Send every possible message to one bankAccount object and show
// the default bankAccount state
#include <iostream.h>
#include "baccount" // For the bankAccount class

int main()
{
  bankAccount anAcct("Moss", 500.00); // Construct an object
  bankAccount defaultAccount;  // Default name is "?name?".
                               // Default balance is 0.00.

  anAcct.withdraw(100.00);                         // Modify state
  anAcct.deposit(40.00);                           // Modify state
  cout << "Name: " << anAcct.name() << endl;       // Access state
  cout << "Balance: " << anAcct.balance() << endl; // Access state
  cout << "Default Name: " << defaultAccount.name() << endl;
  cout << "Default Balance: " << defaultAccount.balance() << endl;

  return 0;
}