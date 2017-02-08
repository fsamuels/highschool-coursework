// This program uses input statements to produce a
// meaningful result that can be used for a variety of examples
#include <iostream.h> // For cin, cout, and endl
#include "string"   // For the string class

int main()
{
  // 0. Initialize some numeric objects
  double c1 = 0.0;
  double c2 = 0.0;
  double g1 = 0.0;
  double g2 = 0.0;
  double GPA = 0.0;
   
  // 1. Input
  cout << "Credits for course 1: ";
  cin >> c1;
  cout << " Grade for course 1: ";
  cin >> g1;
  cout << "Credits for course 2: ";
  cin >> c2;
  cout << " Grade for course 2: ";
  cin >> g2;
  
  // 2. Process
  GPA = ( (g1*c1) + (g2*c2) ) / (c1 + c2);
  
  // 3. Output
  cout << "GPA: " << GPA << endl;

  return 0;
}