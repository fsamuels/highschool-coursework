// This program uses input statements to produce a meaningful
// result that can be used in a variety of examples
#include <iostream.h> // Required to generate output and obtain input
#include "string" // For the string class

int main()
{
  // 0. Initialize some objects
  double credits = 0.0;
  double points = 0.0;
  double GPA = 0.0;
  string firstName;
  string lastName;
  
  // 1. Input
  cout << "Enter first name: ";
  cin >> firstName;
  cout << "Enter last name: ";
  cin >> lastName;
  cout << "Enter credits: ";
  cin >> credits;
  cout << "Enter points: ";
  cin >> points;
  
  // 2. Process
  GPA = points / credits;
  
  // 3. Output
  cout << "Name : " << firstName << " " << lastName << endl;
  cout << "Credits : " << credits << endl;
  cout << "Points : " << points << endl;
  cout << "GPA : " << GPA << endl;
  
  return 0;
}