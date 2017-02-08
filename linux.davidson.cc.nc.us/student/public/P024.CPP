// This C++ program gets a number from the user and displays its squared value
#include <iostream.h>   // For cout, cin, and endl

int main()
{
  // 0. Initialize objects
  double x = 0.0;
  double result = 0.0;

  // 1. Input
  cout << "Enter a number: ";
  cin >> x;

  // 2. Process
  result = x * x;  // The C++ symbol for multiplication is *

  // 3. Output
  cout << x << " squared = " << result << endl;

  return 0;
}
