// file name: test6e.cpp
#include "baccount" 
#include <iostream.h>  
#include "compfun" // causeApause();

int main()
{
  bankAccount anAcct;
  // assert: transaction count should start as 0 at first

  cout << "transaction count = " << anAcct.transactionCount() << endl;
  anAcct.deposit(10.00);
  anAcct.deposit(20.00);
  anAcct.deposit(30.00);
  cout << "after 3 transactions: " << anAcct.transactionCount() << endl;

  bankAccount another("Bob", 100.00);
  // assert:  transaction count should be 0

  another.deposit(25.00);
  cout << "Should be 1: " << another.transactionCount() << endl;

  causeApause();
  return 0;
}

