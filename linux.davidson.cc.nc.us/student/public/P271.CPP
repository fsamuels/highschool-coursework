// 271 275
#include <iostream.h>
#include "string"

string letterGrade(double percentage)
{ // pre: percentage >= 0.0 && percentage <= 100.0
  // post: Return letter grade according to external documentation
  string result;
  
  // Determine the proper result . . .
  if(percentage >= 90.0)
    result = "A";
  else if(percentage >= 80.0)
    result = "B";
  else if(percentage >= 70.0)
    result = "C";
  else if(percentage >= 60.0)
    result = "D";
  else
   result = "F";
  
  // . . . and return it
  return result;
}

int main()
{ // A test driver for string letterGrade(double percentage)
  cout << "90.0: " << letterGrade(90.0) << endl; // 90.0: A
  cout << "80.0: " << letterGrade(80.0) << endl; // 80.0: B
  cout << "70.0: " << letterGrade(70.0) << endl; // 70.0: C
  cout << "60.0: " << letterGrade(60.0) << endl; // 60.0: D
  cout << "59.9: " << letterGrade(59.9) << endl; // 59.9: F

  return 0;
}