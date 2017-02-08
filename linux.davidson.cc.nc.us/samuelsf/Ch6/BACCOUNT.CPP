//--------------------------------------------------------------------
// IMPLEMENTATION FILE: baccount.cpp
//
// Implements 1. class bankAccount member functions
//            2. the six relational operators 
//
//--------------------------------------------------------------------
#include "/student/csc134HA/samuelsf/baccount.h" 
#include <iostream>    // for ostream << and istream >>
#include <string>      // for class string
using namespace std;

//--constructors

bankAccount::bankAccount()
{
  my_transactionCount = 0;
  my_name = "?name?";
  my_balance = 0.0;
}

bankAccount::bankAccount(string initName, double initBalance)
{
  my_transactionCount = 0;
  my_name = initName;
  my_balance = initBalance;
}


//--modifiers

void bankAccount::deposit(double depositAmount)
{
  my_transactionCount = my_transactionCount +1;
  my_balance = my_balance + depositAmount;
}

void bankAccount::withdraw(double withdrawalAmount)
{
  my_transactionCount = my_transactionCount +1;
  my_balance = my_balance - withdrawalAmount;
}


//--accessors

double bankAccount::balance() const
{
  return my_balance;
}

string bankAccount::name() const
{
  return my_name;
}

////////forrest's additions//////////////
int bankAccount::transactionCount() const 
{
	return my_transactionCount;
}
//////////////////end additions/////////

//--auxilliary functions
 
//  These non-member functions may be required by standard C++ 
//  container classes such as list. Without all six defined, you will 
//  likely get many cryptic compiletime error messages.

bool operator < (const bankAccount & left, const bankAccount & right)
{
  return left.name() < right.name();
}

bool operator == (const bankAccount & left, const bankAccount & right)
{
  return left.name() == right.name();
}

bool operator != (const bankAccount & left, const bankAccount & right)
{
  return left.name() != right.name();
}

bool operator > (const bankAccount & left, const bankAccount & right)
{
  return left.name() > right.name();
}

bool operator >= (const bankAccount & left, const bankAccount & right)
{
  return left.name() >= right.name();
}

bool operator <= (const bankAccount & left, const bankAccount & right)
{
  return left.name() <= right.name();
}
