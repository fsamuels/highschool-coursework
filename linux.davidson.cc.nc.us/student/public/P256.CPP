#include <iostream.h>
#include "compfun"  // For decimals(cout, 2);
#include "baccount" // Pretend it is a modified "safe" bankAccount

int main()
{ // Test drive the "safe" bankAccount::withdraw
  bankAccount aSafeAccount("Krista Guido", 50.00);
  double withdrawalAmount;
  
  decimals(cout, 2);
  cout << "Enter amount to withdraw: ";
  cin >> withdrawalAmount;

  // ONLY WORKS IF WITHDRAW RETURNS bool INSTEAD of void
  if(aSafeAccount.withdraw(withdrawalAmount))
  {
    cout << "Success. Balance = $" << aSafeAccount.balance() << endl;
  }
  else
  {
    double over = withdrawalAmount - aSafeAccount.balance();
    cout << "could not withdraw " << withdrawalAmount << endl;
    cout << "You need $" << over << endl;
  }

  aSafeAccount.withdraw(1000.00); // Ignore the return value

  return 0;
}