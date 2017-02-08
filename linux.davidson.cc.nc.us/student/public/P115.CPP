// Show a few string operations
#include <iostream.h> // For the cout object and endl
#include "string"   // For the string class

int main()
{
  string a("Any old");
  string b(" string");
  string aString(a + b); // Concatenate a and b to create a string
  // assert: aString is "Any old string" 2

  cout << aString[0] << endl;
  // assert: aString[0] returned A (C++ begins to count at 0)

  cout << aString[1] << endl;
  // assert: aString[1] returned n (the second letter in aString)

  cout << aString.length() << endl;
  // assert: aString.length returned 14

  cout << aString.find("ring") << endl;
  // assert: aString.find("ring") returned 10

  cout << aString.substr(4, 7) << endl;
  // assert: aString.substr(4, 7) returns the string "old str",
  // which is the seven characters starting at aString[4]

  return 0;
}