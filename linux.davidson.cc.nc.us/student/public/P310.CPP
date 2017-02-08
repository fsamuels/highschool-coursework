// Determine the range of temperatures in a set of known size
#include <iostream.h>

int main()
{
  int aTemp;
  int highest = -9999; // No temperature will be less than -9999
  int lowest = 9999;   // No temperature will be greater than 9999
  int j, n, range;

  cout << "Enter number of temperature readings: ";
  cin >> n;
  // Input first temperature to record it as highest and lowest
  cout << "Enter readings 1 per line" << endl;

  // assert: highest == -9999 and lowest == 9999
  for(j = 1; j <= n; j++)
  {
    cin >> aTemp;
    if(aTemp > highest)
      highest = aTemp;
    else if(aTemp < lowest)
      lowest = aTemp;
  }

  range = highest - lowest;
  cout << "Range: " << range << endl;

  return 0;
}