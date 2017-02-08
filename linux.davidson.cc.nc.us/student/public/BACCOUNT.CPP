//--------------------------------------------------------------------
// IMPLEMENTATION FILE: baccount.cpp
//
// Implements 1. class bankAccount member functions
//            2. the six relational operators 
//
//--------------------------------------------------------------------
#include "baccount.h"  // allows for separate compilation if you want
#include <iostream.h>    // for ostream << and istream >>
#include "string"      // for class string

//--constructors

bankAccount::bankAccount()
{
  my_name = "?name?";
  my_balance = 0.0;
}

bankAccount::bankAccount(string initName, double initBalance)
{
  my_name = initName;
  my_balance = initBalance;
}

//--modifiers

void bankAccount::deposit(double depositAmount)
{
  my_balance = my_balance + depositAmount;
}

void bankAccount::withdraw(double withdrawalAmount)
{
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
