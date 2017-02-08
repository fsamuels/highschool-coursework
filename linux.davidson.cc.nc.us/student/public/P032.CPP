// This C++ program gets a number and displays its squared value
#include <iostream.h>  // 1. Nonstandard compilers need .h after iostream

// 2. Do not write using namespace std;

int main()
{
  // a. Initialize objects
  double x = 0.0;
  double result = 0.0;

  // b. Input
  cout << "Enter a number: ";    
  cin >> x;
 
  // c. Process
  result = x * x;  // The C++ symbol for multiplication is *

  // d. Output
  cout << x << " squared = " << result << endl;

  return 0;  // This avoids warnings on older compilers
}
