// p348
// Use the end-of-file event to terminate a loop
#include <iostream.h> // For cin, cout, and endl

int main()
{
  double x = 0.0, sum = 0.0;
  int n = 0;

  cout << "Enter doubles, Ctrl-D, Ctrl-Z,"
       << " or Command-Period to quit" << endl;

  while(cin >> x)
  { // assert: cin is not at end of file, so process input
    sum = sum + x;
    n++;
  }

  if(n > 0)
  {
    cout << "Average: " << (sum / n) << endl;
  }
  else
  {
    cout << "Can't average 0 numbers" << endl;
  }

  return 0;
}