#include <iostream.h> // For cout <<
#include <string> // For the standard string class
#include <algorithm> // For find(iterator, iterator, object)
// SKIP THIS UNLESS YOU HAVE A STANDARD COMPILER
#include <list> // For list<Type>
//using namespace std;

int main ()
{ // list and iterator constructors
  list<string> stringList;
  list<string>::iterator si;

  stringList.push_back("One");
  stringList.push_back("Two");
  stringList.push_back("Three");
  stringList.push_back("Four");
  stringList.push_back("Five");
  si = find(stringList.begin(), stringList.end(), "Three");
 
  if(si != stringList.end())
  { // Found it before reaching the end of the list
    cout << "\nFound '" << (*si)
         << "'. Now modify it in the list." << endl;
    *si = *si + " 'modified with the iterator object'";
  }
  else
  { // Didn't find it
    cout << "\nThree not found" << endl ;
  }

  stringList.sort(); // Sort the list in ascending order
  cout << "\nThe strings after sorting: " << endl;
  for(si = stringList.begin(); si != stringList.end(); si++)
  {
     cout << (*si) << endl ;
  }

  return 0;
}
