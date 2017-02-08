// This program uses a generic search routine to search for objects stored
// in different classes of vectors
#include "vector"
#include "string"
#include <iostream.h>

// THIS DOES NOT WORK IN CODEWARRIOR

template<class VectorType>
int locationOf(const vector<VectorType> & v, int n, VectorType searchItem)
{ // pre: The type must have the != operator available
  // post: Return the index of searchItem in the vector or -1 if not found
  int result = -1;
  int subscript = 0;

  while( (subscript < n) && (searchItem != v[subscript]) )
  {
    subscript++;
  }
  if(subscript < n) // searchItem was found
    result = subscript;
  return result;
}

int main()
{
  const int n = 3;
  vector <int> x(n);
  x[0] = 1111;
  x[1] = 2222;
  x[n-1] = 3333;
  cout << locationOf(x, n, 3333) << endl;
  cout << locationOf(x, n, 9999) << endl;
  vector <string> s(n);

  s[0] = "first";
  s[1] = "second";
  s[n-1] = "third";
//  cout << locationOf(s, n, string("first")) << endl;
 // cout << locationOf(s, n, string("not there")) << endl;

  return 0;
}
