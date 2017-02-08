#include <iostream.h>
#include "baccount"

int main()
{
  bankAccount anAcct("both (*bp) and bp-> work ", 100.00);
  bankAccount* bp;
  
  bp = &anAcct;

  // Wrap the dereference in parentheses because the dereference
  // operator * has lower precedence than function calls
  (*bp).deposit(123.45);
  cout << (*bp).name() << (*bp).balance() << endl;

  // Use -> for pointers to objects other than int or double
  bp->withdraw(111.11);
  cout << bp->name() << bp->balance() << endl;

  return 0;
}