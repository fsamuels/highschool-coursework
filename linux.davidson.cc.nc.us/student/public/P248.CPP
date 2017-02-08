// Demonstrate a simple bool function
#include <iostream.h>




bool odd(int n)
{ // post: Return true if n is an odd integer
  return (n % 2) != 0;
}

int main()
{
  int j = 3;

  // Ensure j is an even number
  if(odd(j))
  {
    j = j + 1;
  }
  cout << j << endl;

  return 0;
}
