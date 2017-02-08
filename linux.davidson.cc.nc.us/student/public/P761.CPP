#include <iostream.h>

void forward(int n)
{
  if(n > 1)
  {
    forward(n - 1);
    // RP# FORWARD
  }
  cout << n << endl;
}

int main()
{
  int arg = 3;
  
  forward(arg);
  // RP# MAIN
  cout << "In main: " << arg << endl;

  return 0;
}