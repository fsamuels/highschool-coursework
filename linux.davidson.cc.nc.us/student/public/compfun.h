//----------------------------------------------------------------------
// SPECIFICATION FILE compfun.h
//
// Declares: An assortment of functions for use with the textbook
//              'Computing Fundamentals with C++', 2nd edition
//----------------------------------------------------------------------
#ifndef COMPFUN
#define COMPFUN
#include <iostream.h>   // for class ostream  and class istream
// using namespace std;

void clearScreen();
// pre:  the correct system call exist for your system
// post: the sceeen is cleared 

void causeApause();
// post: // Make user press the Enter (or Return) key before continuing

double round(double x);
// post: rounds x to the nearest integer

double round(double x, int n);
// post: rounds x to the nth decimal place

long decimals(ostream & cout, int n );
// pre: n > 0 ;

void flush(istream & is);
// call istream::clear and extract any garbage until end of file

#endif   // COMPFUN
