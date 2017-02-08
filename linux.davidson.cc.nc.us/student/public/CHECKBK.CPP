// File name checkbk.cpp
#include "string"      // for a string class
#include <iostream.h>  // for cout

////////////// Define class checkBook //////////////
class checkBook {
public:  // MEMBER FUNCTIONS
//--constructors
  checkBook();

  checkBook(string initialAcctID, double initialBalance);
  // post: construct a checkBook object with client supplied initial state
  
//--modifiers
  void check(int checkNumber, double amount);
  // post: displays the check number, check amount and increments the number of checks

  void deposit(double amount);
  // post: displays the deposit amount

  void ATMWithdraw(double amount);
  // post: displays the ATM withdrawal amount and increments the number of ATMS

  void applyMonthlyCharge();
  // post: deduct the monthly bank fee based on local rules 
  //       while deducting that charge from the balance

//--accessor
  double balance() const;
  // post: returns the current checkbook balance

private:  // STATE
  string my_name;
  double my_balance;
  int my_checksWritten;
  int my_ATMCount;
};

checkBook::checkBook(string initialAcctID, double initialBalance)
{
  decimals(cout, 2);
  my_name = "?ID?";
  my_balance = 0.0;
  my_ATMCount = 0;
  my_checksWritten = 0;
}

checkBook::checkBook(string initialAcctID, double initialBalance)
{ 
  decimals(cout, 2);
  my_acctID = initialAcctID;
  my_balance = initialBalance;
  my_ATMCount = 0;
  my_checksWritten = 0;
}
  
void checkBook::check(int checkNumber, double amount)
{ my_balance = my_balance - amount;
  my_checksWritten = my_checksWritten + 1;
  cout.width(7);
  cout << checkNumber;
  cout.width(10);
  cout << amount;
  cout.width(20);
  cout << my_balance << endl;
}

void checkBook::deposit(double amount)
{ my_balance = my_balance + amount;   
  cout << "Deposit";
  cout.width(20);
  cout << amount;
  cout.width(10);
  cout << my_balance << endl;
}

void checkBook::ATMWithdraw(double amount)
{
  my_balance = my_balance - amount;   
  my_ATMCount = my_ATMCount + 1;
  cout << "ATM    ";
  cout.width(10);
  cout << amount;
  cout.width(20);
  cout << my_balance << endl;
}
  
void checkBook::applyMonthlyCharge()
{ 
  double fee(0.0);
  fee = 5.00 + 0.50 * my_ATMCount + 0.25 * my_checksWritten;
  my_balance = my_balance - fee;
  cout << "Fee    ";
  cout.width(10);
  cout << fee;
  cout.width(20);
  cout << my_balance << endl;
}

double checkBook::balance()  const
{ 
  return my_balance;
}

