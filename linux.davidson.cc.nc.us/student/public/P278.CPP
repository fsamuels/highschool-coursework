// Use some char objects
#include <iostream.h>

int main()
{ // Declare and initialize some char objects
  char one, two;
  char letterGrade = 'A';
  char newLine = '\n';
  
  // Assignment is possible with character expressions
  one = 'T';
  two = 'o';
  // Output some char objects, char constants, and escape sequences
  cout << "letterGrade is " << letterGrade << endl;
  cout << one << two << newLine << one << '\t' << two << endl;
  cout << '\"' << 'A' << ' ' << '\\' << ' ' << 'S' << 't'
  << 'r' << 'i' << 'n' << 'g' << '?' << '\'' << endl;

  return 0;
}