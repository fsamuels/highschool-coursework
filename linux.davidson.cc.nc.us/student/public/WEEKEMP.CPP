//--------------------------------------------------------------------
// IMPLEMENTATION FILE: weekemp.cpp
//
// Implements: 1. class weeklyEmp
//             2. cout << weeklyEmp
//             3. cin >> weeklyEmp
//       Note: This file is automatically included by ouremp.h
//--------------------------------------------------------------------

#include <iostream.h>   // for cout, cin, istream, ostream
#include <math.h>      // for floor
#include "string"     // for class string
#include <stdlib.h>   // for exit(0);
#include <ctype.h>    // for toupper(char);
#include "compfun"    // for decimals(cout, 2) and round (tax, 2)
#include "weekemp.h"

// The value of WEEKLY_ALLOWANCE has changed almost every year so the
// named constant must be checked every year for proper maintenance
// Use IRS publication Circular E, Employer's Tax Guide each new year.
const double WEEKLY_ALLOWANCE = 39.42;
const int    MAX_EXEMPTIONS = 99;
const double FICA_TAX_RATE = 0.0765;

//--constructors

weeklyEmp::weeklyEmp()
{ // Default constructor used to allow for arrays.
  my_name = " ?name? ";
  my_hours = 0.00;
  my_rate = 0.00;
  my_exemptions = 0;
  my_filingStatus = "?status?";
}

weeklyEmp::weeklyEmp(string initName,
                     double initHours,
                     double initRate,
                     int    initExemptions,
                     string initStatus)
{ // Five argument constructor
  my_name = initName;
  my_hours = initHours;
  my_rate = initRate;

  my_exemptions = initExemptions;
  if((my_exemptions < 0) || (my_exemptions > MAX_EXEMPTIONS))
  {
	  cout << "**Error** Exemptions for "
         << initName << " == " << initExemptions << endl;
    cout << "Exemptions must be in the range of 0.." << MAX_EXEMPTIONS
         << endl;
    cout << "**Program Terminated**"
         << endl;
    exit(0);
  }
  
  if(initStatus == "s" || initStatus == "S")
    my_filingStatus = "S";
  if(initStatus == "m" || initStatus == "M")
    my_filingStatus = "M";
  if ( ! (my_filingStatus == "S" || my_filingStatus == "M") )
  {
    cout << "Filing Status for " << initName << " == " << my_filingStatus
         << endl;
    cout << "Status must be one of these four strings \"s\", \"S\", \"m\", or \"M\""
         << endl;
    cout << "Terminating program"
         << endl;
    exit(0);
  }
}

weeklyEmp::weeklyEmp(const weeklyEmp & source)
{ // Copy constructor
  my_name = source.my_name;
  my_hours = source.my_hours;
  my_rate = source.my_rate;
  my_exemptions = source.my_exemptions;
  my_filingStatus = source.my_filingStatus;
}


//--modifiers

void weeklyEmp::set_hours(double thisWeeksHours)
{ // post: set the hours worked for a given week
  my_hours = thisWeeksHours;
}


void weeklyEmp::set_rate(double thisWeeksRate)
{
  my_rate = thisWeeksRate; 
}

// -- accessors
double weeklyEmp::grossPay()  const
{
  double result(0.0);

  if(my_hours <= 40)
	 result = my_hours * my_rate;
  else
	 result = 40 * my_rate + 1.5 * my_rate * (my_hours - 40);

  // round to the nearest penny
  result = round(result, 2);
  
  return result;
}

double weeklyEmp::incomeTax()  const
{
  double result(0.0);
  double taxableIncome(grossPay() - my_exemptions * WEEKLY_ALLOWANCE);

  if(my_filingStatus == "S")
  {
	 if (taxableIncome <= 23.00)
		result = 0.00;
    else if(taxableIncome <= 397.00)
      result = 0.15 * (taxableIncome - 23.00);
    else if(taxableIncome <= 928.00)
      result = 56.10 + 0.28 * (taxableIncome - 397.00);
    else if(taxableIncome <= 2121.00)
      result = 204.78 + 0.33 * (taxableIncome - 928.00);
    else
      result = 598.47 + 0.28 * (taxableIncome - 2121.00);
  }

  if(my_filingStatus == "M")
  {
    if(taxableIncome <= 65.00)
      result = 0.00;
    else if(taxableIncome <= 689.00)
      result = 0.15 * (taxableIncome - 65.00);
    else if(taxableIncome <= 1573.00)
      result = 93.60 + 0.28 * (taxableIncome - 689.00);
    else if(taxableIncome <= 3858.00)
      result = 341.12 + 0.33 * (taxableIncome - 1573.00);
    else
      result = 1095.17 + 0.28 * (taxableIncome - 3858.00);
  }

  // round to the nearest penny
  result = round(result, 2);
  
  return result;
}

double weeklyEmp::FICATax()  const
{
  double result(FICA_TAX_RATE * grossPay());

  // round to the nearest penny
  result = round(result, 2);
  return result;
}

string weeklyEmp::name()  const
{
  return my_name;
}


bool operator <  (const weeklyEmp& left, const weeklyEmp& right)
{
   return (left.name() < right.name());  // string defines <
}

bool operator == (const weeklyEmp& left, const weeklyEmp& right)
{
   return (left.name() == right.name()); // string defines ==
}

bool operator <= (const weeklyEmp& left, const weeklyEmp& right)
{
   return (left.name() <= right.name()); // string defines <=
}

bool operator >= (const weeklyEmp& left, const weeklyEmp& right)
{
   return (left.name() >= right.name()); // string defines >=
}

bool operator > (const weeklyEmp& left, const weeklyEmp& right)
{
   return (left.name() > right.name()); // string defines >
}

bool operator != (const weeklyEmp& left, const weeklyEmp& right)
{
   return (left.name() != right.name()); // string defines >
}

