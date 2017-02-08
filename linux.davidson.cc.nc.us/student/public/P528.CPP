// Demonstrate list, one of the standard container classes
#include <iostream.h>
// SKIP THIS IF YOU DO NOT HAVE A STANDARD LIST CLASSS
#include <list> // For the list class

int main()
{
  list <int> intList; // intList may store a collection of ints
  
  cout << "intList.size() == " << intList.size() << endl;
  // "Push" five new int objects onto the "back" of the list
  intList.push_back(111);
  intList.push_back(222);
  intList.push_back(333);
  intList.push_back(444);
  intList.push_back(555);

  // Remove an item that is in the list
  // and attempt to remove one that is not
  intList.remove(333); // Remove 333
  intList.remove(999); // Not found

  // assert: There are four (4) elements in the container intList
  // assert: The first in the sequence is 111 and the last is 555
  // Show the number of objects in the container
  cout << "intList.size() == " << intList.size() << endl;

  return 0;
}
