// file name: test10f.cpp
#include <iostream>
// using namespace std;
typedef double ARRAY_ELEMENT_TYPE;
#include "myarray"    // for class myArray
#include "compfun" // causeApause();

void show(myArray arrayCopy, int n)
{
  for(int j = 0; j < n; j++)
  {
    cout << arrayCopy.sub(j) << endl;
  }
}

int main()
{
  int n = 6;
  myArray a(6);
  a.set(0, 1.1);
  a.set(1, 2.2);
  a.set(2, 3.3);
  a.set(3, 4.4);
  a.set(4, 5.5);
  a.set(5, 6.6);
  
  show(a, n);

  cout << a.sub(6) << endl;

  causeApause();
  return 0;
}