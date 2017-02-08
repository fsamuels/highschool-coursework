#include <iostream.h> // For the cout and cin objects
#include "string"   // For a string class

int main()
{ // <- Without the left curly brace, there were 12 errors!
  double x;
  string str;
  
  cout << "Enter a double: ";
  cin >> x;
  
  cout << "Enter a string: ";
  cin >> str;

  return 0;
}