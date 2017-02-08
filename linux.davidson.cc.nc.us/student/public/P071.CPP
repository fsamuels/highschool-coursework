// Round a given number to a specific number of decimal places
#include <iostream.h> // For cin and cout
#include <math.h> // For pow(10, n) and floor(x)

int main()
{
  // Declare objects identified during analysis
  double x = 0.0;
  double n = 0.0;
                          // Algorithm step number:
  // Input
  cout << "Enter number to round : ";           // 1.
  cin >> x;                                     // 2.
  cout << "Enter number of decimal places : " ; // 3.
  cin >> n;                                     // 4.
 
  // Process (Round x to n decimals)
  x = x * pow(10, n);                           // 5a.
  x = x + 0.5;                                  //  b.
  x = floor(x);                                 //  c.
  x = x / pow(10, n);                           //  d.


  // Output (Display the modified state of x)
  cout << "Rounded number : " << x << endl;     // 6.
  
  return 0;
}
