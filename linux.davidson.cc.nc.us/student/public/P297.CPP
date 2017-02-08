// Determine the average of n inputs. The user must supply n.
#include <iostream.h> // For cout, cin, and endl
// using namespace std;

int main()
{
  int n = 0; // The number of inputs--supplied by user
  double sum = 0.0; // Keep running sum
  double number; // Temporarily store each input
  double average; // Holds the average for potential future use
  int j; // The loop counter

  cout << "How many numbers do you need to average? ";
  cin >> n;
  for(j = 1; j <= n; j = j + 1)
  {
    cout << "Enter number: ";
    cin >> number;
    sum = sum + number;
  }
  average = sum / n;
  cout << "Average of " << n << " numbers is " << average;
 
  return 0;
}