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
  // Use a determinate loop to process n temperatures
  for(j = 1; j <= n; j++)
  {
    // Get the next input
    cin >> aTemp;
    // Update the highest so far, if necessary
    if(aTemp > highest)
      highest = aTemp;
    // Update the lowest so far, if necessary
    if(aTemp < lowest)
      lowest = aTemp;
  }

  range = highest - lowest;
  cout << "Range: " << range << endl;

  return 0;
}