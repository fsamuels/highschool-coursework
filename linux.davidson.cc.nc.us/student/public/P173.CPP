// Use references to return more than one value
#include <iostream.h>
#include "string"

void getData(string & name, int & age); // Avoid Codewarrior warning

void getData(string & name, int & age) // Reference parameters
{ // post: Returns a person's name and age
  string first, middle, last;
  cout << "Enter your first name: ";   cin >> first;
  cout << " your middle initial: ";    cin >> middle;
  cout << " and your last name: ";     cin >> last;
  name = last + ", " + first + " " + middle + ".";
  cout << " Enter your age: ";         cin >> age;
}

int main()
{
  string name;
  int age = 0;

  getData(name, age);
  // assert: name and age have been modified
  cout << name << " will be " << age + 1 << " next year" << endl;

  return 0;
}