// file name: test11e.cpp
#include <iostream>
// using namespace std;
#include "compfun" // causeApause();

typedef int SET_ELEMENT_TYPE;
#include "set" // includes set.h and set.cpp AFTER you create them

// You need to create set.h and set.cpp

display(set aSet)
{
  // YOU COMPLETE THIS FUNCTION
}

int main()
{ // Test drive class set
  set aSet;
  aSet.remove(99);  // Try to remove an element from an empty set
  cout << "size: " << aSet.size() << endl;
  cout << "capacity: " << aSet.capacity() << endl;
  
  cout << "The empty set: "; 
  // ITERATE OVER THE SET TO SHOW IT, YOU WRITE THE CODE
 
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
  
  cout << "The set: "; 
  // ITERATE OVER THE SET TO SHOW IT, YOU WRITE THE CODE

  causeApause();

  return 0;
}
