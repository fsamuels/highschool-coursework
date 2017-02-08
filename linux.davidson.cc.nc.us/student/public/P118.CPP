// Send two precision messages to the ostream object named cout
#include <iostream.h>

int main()
{
  double x = 1.23456;

  cout << x << endl; // Default (1.23456)
  cout.precision(1); // Modify the state of cout
  cout << x << endl; // Show only one significant digit (1)
  cout.precision(4); // Modify the state of cout
  cout << x << endl; // Show four digits rounded (1.235)

  return 0;
} 