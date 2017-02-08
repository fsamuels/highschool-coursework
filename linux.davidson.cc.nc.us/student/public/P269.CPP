// Multiple selection where exactly one cout statement executes.
// The output is dependent on the input value for GPA.
#include <iostream.h>

int main()
{
  double GPA;
  cout << "Enter your GPA: ";
  cin >> GPA;
  if(GPA < 3.5)
  {
    cout << "Try harder" << endl;
  }
  else
  { // Execute this multiple selection statement
    if(GPA < 4.0)
      cout << "You made the dean's list" << endl;
    else
      cout << "You made the president's list" << endl;
  }

  return 0;
}