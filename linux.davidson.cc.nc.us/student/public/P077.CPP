#include "compfun" // For causeApause() and clearScreen()
#include <iostream.h> // For cout

int main()
{
  cout << "This program calls functions that don't return values." << endl;
  
  causeApause();

  cout << "You won't see me until you've pressed the Enter key." << endl;

  clearScreen();
  cout << "Now you'll see me on a screen that is emp-tee." << endl;
  causeApause();
  
  return 0;
}