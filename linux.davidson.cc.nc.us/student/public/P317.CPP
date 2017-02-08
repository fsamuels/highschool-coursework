// 317

// Use a sentinel of -1 to terminate a loop
#include <iostream.h>

int main()
{
  const double sentinel = -1.0; // User enters this to terminate
  double accumulator = 0.0;     // Maintain running sum of inputs
  int n = 0;                    // Maintain total number of inputs
  double testScore, average;

  // Prompt
  cout << "Enter test scores [0.0 through 100.0] or " << sentinel
       << " to quit" << endl;

  // Input and process at the same time
  while( (cin >> testScore) && (testScore != sentinel) )
  {
    accumulator += testScore; // Update accumulator
    n++; // Update total inputs
  }

  if(n > 0)
  {
    average = accumulator / n;
    cout << "Average of " << n << " tests = " << average << endl;
  }
  else
    cout << "Can't average 0 numbers" << endl;

  return 0;
}
