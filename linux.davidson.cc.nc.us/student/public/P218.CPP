// Illustrate connection between member functions tagged as const
// functions and passing an object of that class as const parameter
#include <iostream.h> // For cout and endl
#include "baccount" // For the bankAccount class

void display(const bankAccount & b); // Avoid CodeWarrior warning

void display(const bankAccount & b)
{
  // OKAY to send name and balance messages--they are declared const
  cout << "{ bankAccount: " << b.name()
       << ", $" << b.balance() << " }" << endl;
  // This modifying message to a nonconst member function was not
  // tagged as a const member, so this should be an error:
  b.withdraw(234.56); // ERROR
}

int main()
{
  bankAccount anAcct("Rita Jupe", 1234.56);

  display(anAcct);

  return 0;
}
