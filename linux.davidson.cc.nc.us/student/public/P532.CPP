// Demonstrate list and list iterator objects
#include <list> // For the standard list class
// SKIP THIS UNLESS YOU HAVE A STANDARD COMPILER
#include <iostream.h>
#include "string"   

int main()
{
  list<string> presidents;
  list<string>::iterator p;

  presidents.push_back("George Washington");
  presidents.push_back("John Adams");
  presidents.push_back("Thomas Jefferson");
  presidents.push_back("James Madison");
  presidents.push_back("James Monroe");
  cout << "The first " << presidents.size()
       << " presidents of the United States: " << endl;

  for(p = presidents.begin(); p != presidents.end(); p++)
  {
    cout << (*p) << endl;
  }

  return 0;
}
