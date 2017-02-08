//----------------------------------------------------------------------
// IMPLEMENTATION FILE compfun.cpp
//
// Imnplenents: An assortment of functions for use with the textbook
//              'Computing Fundamentals with C++', 2nd edition
//              Rick Mercer
//              Copyright Franklin, Beedle, and Associates
//----------------------------------------------------------------------
#include <iostream.h>   // for cout and class ostream  (needed in decimals)
#include <math.h>      // for pow and ceil
#include <stdio.h>    // for getchar()
#include <stdlib.h>   // for time, srand, and system("operating system command")
#include <time.h>     // for struct time
#include "compfun.h"  // allow for separate compile


// using namespace std;

void clearScreen()
{
// TODO: Find a define for either DOS, Windows, or MacOS so I can get three, not 2 OSs
  system("clear");

}

void causeApause()
{
  cout << "\n. . . Press Enter to continue . . . " ;
  cout.flush();
  getchar();   // Make user press the Enter (or Return) key
}

double round(double x)
{
  return ceil(x - 0.5);
}

double round(double x, int n)
{
  if (n < 0)
  {
    return x;
  }
  else 
  {
    double factor = pow(10.0, n);
    return ceil(x * factor - 0.5) / factor;
  }
}

// Used by decimals to reestablish initial default characteristics
// of the system after decimals has been used to alter the format
static long defaultFlags = cout.flags();
static int defaultPrecision = cout.precision();
static long int default_x_flags = cout.setf(0);

long decimals(ostream & cout, int n )
{ // Note: This function affects any ostream object
  long oldFlags = cout.flags();
  if(n==0)
  {
    // Reset format to default
    cout.flags(defaultFlags);
    cout.precision(defaultPrecision);
    cout.setf(default_x_flags);
  }
  else if(n > 0 ) 
  {
    // Change the output stream to show decimal point and 
    // n decimal places for any subsequent float or double.
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(n);
  }
  // Allow user to get a value to return
  // output stream to original state
  return oldFlags;
}

void flush(istream & is)
{ // call istream::clear and extract any garbage until end of file
  is.clear();
  char nextChar;
  while( (nextChar = (char)is.get()) != '\n' && nextChar != EOF) { }
  is.clear();
}


