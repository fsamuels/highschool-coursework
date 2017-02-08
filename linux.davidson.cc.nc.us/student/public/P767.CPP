#include <iostream.h>

double factorial(int n)
{ // pre: n >= 0 and n is not too large
  if( n == 0 ) // Base case
    return 1;
  else
    return n * /* RP# FACT */ factorial(n - 1); // Recursive case
}

int main()
{
  cout << /* RP# MAIN */ factorial(3) << endl; // 24

  return 0;
}