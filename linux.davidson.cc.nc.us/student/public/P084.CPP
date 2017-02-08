// This program provides an example of int division with '/' for
// the quotient and '%' for the remainder
#include <iostream.h>

int main()
{
  // Declare objects that will be given meaningful values later
  int totalMinutes, minutes, hours;
  double fractionalHour;

  // Input
  cout << "Enter total minutes: ";
  cin >> totalMinutes;

  // Process 
  fractionalHour = totalMinutes / 60.0;
  hours = totalMinutes  / 60;
  minutes = totalMinutes % 60; 

  // Output
  cout <<  totalMinutes  << " minutes can be rewritten as "
       << fractionalHour << " hours " << endl;  // Shows a fraction
  cout << "or as "
       << hours   << " hours and "
       << minutes << " minutes"       << endl;

  return 0;
}
