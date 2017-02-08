// Notice the reference symbol & is in front of parmOne and
// parmTwo. Now a change to parmOne or parmTwo alters the
// associated object argument.
#include <iostream.h>

void swap(int & parmOne, int & parmTwo); // Avoid Codewarrioe warning

// & means that any change to the parameter also alters argument
void swap(int & parmOne, int & parmTwo)
{
  int temp;
  temp = parmOne;
  parmOne = parmTwo;  // Change argument argOne in main
  parmTwo = temp;     // Change argument argTwo in main
}

int main() // argOne: argTwo:
{
  int argOne = 89, argTwo = 76;            // 89 76
  cout << argOne << " " << argTwo << endl;
  swap(argOne, argTwo);                    // 76 89
  cout << argOne << " " << argTwo << endl;

  return 0;
}