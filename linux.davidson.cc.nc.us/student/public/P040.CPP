// A program that declares and/or initializes objects only
#include <iostream.h>
#include "string"

int main()
{
  double credits;
  // The state of credits is unknown!

  double points = 0.0;
  double GPA = 0.0;
  // Both points and GPA are completely initialized

  string firstName;
  string lastName = "Goldman";

  // . . . nothing visible happens
  return 0;
}
