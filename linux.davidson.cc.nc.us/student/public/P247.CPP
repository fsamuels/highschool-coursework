// Demonstrates the bool type. A standard C++
// compiler has bool, true, and false built in.
#include <iostream.h>


int main()
{
  // Initialize three bool objects to false
  bool ready, willing, able;
  double credits = 28.5;
  double hours = 9.5;

  // Assign true or false to all three bool objects
  ready = hours >= 8.0;
  willing = credits > 20.0;
  able = credits <= 32.0;
  
  // If all three bools are true, the logical expression is true
  if(ready && willing && able)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}
