#include <iostream.h>

template<class TheClass>
TheClass lesser(TheClass a, TheClass b)
{ // pre: The class must have a default constructor
  // post: Return the lesser of the two arguments
  TheClass result;
  if(a < b)
    result = a;
  else
  result = b;
 
  return result;
}

int main()
{ // Test drive a function template
  cout << lesser(-12, 23) << endl;
  cout << lesser(0.01, 0.009) << endl;
  cout << lesser('a', 'A') << endl;
  cout << lesser("Baker", "Able") << endl;

  return 0;
}