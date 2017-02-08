#ifndef WEEKEMP_H
#define WEEKEMP_H    // ensure the class definition is compiled only once
#include <iostream.h>  // for class ostream and istream
#include "string"    // for class string
#include "bool"

////////////////////////////////////////////////////////////////////
//// Define class weeklyEmp ////////////////////////////////////////
////////////////////////////////////////////////////////////////////

class weeklyEmp {
public: 
//--constructors
  weeklyEmp();

  weeklyEmp(string initName,  
            double initHours, 
            double initRate,
            int initExemptions, 
            string initFilingStatus );
  // post: A weeklyEmp object is initialized with 5 arguments like this:
  //         weeklyEmp anEmp("Hall, Rob", 40.0, 9.75, 3, "M");
  //       The fourth argument must be in the range of 0 to 99
  //       The last argument is either "M" for married or "S" for single

  weeklyEmp(const weeklyEmp & source);
  // This copy sonctructor is discussed in Chapter 10: Pointers

//--modifiers
  void set_hours(double thisWeeksHours);
  // post: set the hours worked for a given week

  void set_rate(double thisWeeksRate);
  // post: change the employees hourly rate of pay 
//--accessors
  double grossPay() const;
  // post: return gross pay with overtime

  double incomeTax() const;
  // post: return the federal income tax

  double FICATax() const;
  // post: return the social security tax

  string name() const;
  // post: return the employee's name

 private: 
  string my_name;
  double my_hours;
  double my_rate;
  int my_exemptions;
  string my_filingStatus;
};

//--auxilary functions 

bool operator <  (const weeklyEmp& left, const weeklyEmp& right);
// Return true if left's name alphabetically precedes right's name 

bool operator == (const weeklyEmp& left, const weeklyEmp& right);
// Return true if left's name is equal to right's name (case sensitive)

// The file weekemp.cpp includes compfun so you'll also get 
// the other four relational operators >, <=, >=, and !=

#endif


