// String input is separated by one or more spaces or a new line
#include <iostream.h> // For the cin and cout objects
#include "string"   // For the string class

int main()
{
  // Initialize objects
  double aNumber = 0.0;
  string aString;

  // Prompt then Input
  cout << "Enter number: ";
  cin >> aNumber;
  
  // Prompt then Input
  cout << "Enter string: ";
  cin >> aString;
  
  return 0;
}
