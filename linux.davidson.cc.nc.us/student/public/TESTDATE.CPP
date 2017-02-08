// file name: test7g.cpp
#include "date"       
#include <iostream.h>  // for cout in Turbo
//using namespace std;

int main()
{
  Date today;
  cout << today.ToString() << endl;

  Date d(1,1,1960);       // 1960 is a leap year
  d++;                     // d represents January 2, 1960
  d--;                     // d is back to January 1, 1960
  d += 31;                 // d is February 1, 1960
  d -= 32;                 // d is December 31, 1959
  Date d2 = d + 1;         // d2 is January 1, 1960
  Date d3 = 365 + d2;      // d3 is December 31, 1961
  Date d4 = d - 1;         // d4 is December 30, 1959


  cout << today.Month() << endl;
  cout << today.Day() << endl;
  cout << today.DaysIn() << endl;
  cout << today.DayName() << endl;
  cout << today.MonthName() << endl;
  cout << today.Absolute() << endl;
  return 0;
}
