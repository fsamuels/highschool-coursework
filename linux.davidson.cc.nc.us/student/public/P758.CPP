// Recursive version
#include <iostream.h>

long int recursivePower(int x, int n)
{ // pre: x and n are positive. x!=0.
  if(n == 0)
    return 1;
  else
    return x * recursivePower(x, n-1);
}

int main()
{
   cout << recursivePower(2, 3) << endl;
   cout << recursivePower(3, 2) << endl;
   cout << recursivePower(2, 0) << endl;
   cout << recursivePower(2, 1) << endl;
   cout << recursivePower(5, 2) << endl;
   cout << recursivePower(5, 3) << endl;
   cout << recursivePower(2, 10) << endl;

   return 0;
}
