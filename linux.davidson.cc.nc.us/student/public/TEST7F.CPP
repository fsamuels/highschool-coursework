// file name: test7f.cpp
#include <iostream>
// using namespace std;
#include "compfun" // causeApause();

bool leapYear(int year)
{ // post: Return true if year is/was a leap year
  //       Return false if year is/was not a leap year
  // ...   
  // Complete leapYear here
  // ...   
}

int main()
{ //  Test drive leapYear                       // Expected Output
  cout << "1900: " << leapYear(1900) << endl;   // 1900: 0
  cout << "1998: " << leapYear(1998) << endl;   // 1998: 0
  cout << "2000: " << leapYear(2000) << endl;   // 2000: 1
  cout << "2004: " << leapYear(2004) << endl;   // 2040: 1
  cout << "2100: " << leapYear(2100) << endl;   // 2100: 0

  causeApause();
  return 0;

}
