// file name test10n.cpp
typedef int SET_ELEMENT_TYPE;
#include "set" // includes set.h and set.cpp
#include <iostream>
// using namespace std;
#include "compfun" // causeApause();

int main()
{ // Test drive class set
  set aSet;
  
  aSet.remove(99);  // Try to remove an element from an empty set
  cout << "size: " << aSet.size() << endl;
  cout << "capacity: " << aSet.capacity() << endl;
  aSet.display();

  aSet.add(7); 
  aSet.add(9);
  aSet.add(10);
  aSet.add(10);
  aSet.add(8);
  aSet.add(9);

  add.remove(7);     // Remove an existing element
  aSet.remove(12);   // Try to remove a non-existent element

  cout << "size: " << aSet.size() << endl;
  cout << "capacity: " << aSet.capacity() << endl;
  aSet.display();

  causeApause();
  return 0;
}
