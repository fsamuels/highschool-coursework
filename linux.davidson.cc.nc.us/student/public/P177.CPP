// Show the default appearance of floating-point numbers
#include <iostream.h> // For cout

int main()
{
  double money = 112.50;

  // Preferred output (two decimals):
  cout << money << endl; // 112.50
  money = 123.00; // 123.00
  cout << money << endl; // 1234567890.00
  money = 1234567890.00;
  cout << money << endl;

  return 0;
}
