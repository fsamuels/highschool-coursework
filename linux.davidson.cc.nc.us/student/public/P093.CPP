// When this program is run and 0 is entered for n, 
// a runtime error occurs (division by 0)
#include <iostream.h>

int main()
{
  double sum = 0.0;
  double average = 0.0;
  int n = 0;

  // Input
  cout << "Enter sum : ";
  cin >> sum;
  cout << "Enter n : ";
  cin >> n;

  // Process
  average = sum / n;
 
  // Output
  cout << "Average : " << average << endl;

  return 0;
}