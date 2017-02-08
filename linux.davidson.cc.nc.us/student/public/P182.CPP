// This program shows the sizes of several classes
#include "baccount" // For the bankAccount class
#include "grid"     // For the grid class
#include <iostream.h>

int main()
{
  cout << "One int is " << sizeof(int) << " bytes" << endl;
  cout << "One double is " << sizeof(double) << " bytes" << endl;
  cout << "One bankAccount is " << sizeof(bankAccount) << " bytes" << endl;
  cout << "One ostream object is " << sizeof(ostream) << " bytes" << endl;
  cout << "One grid object is " << sizeof(grid) << " bytes" << endl;
  
  return 0;
}