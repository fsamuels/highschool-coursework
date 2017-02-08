// This test driver creates a small bag of strings
#include <iostream.h>
#include "string"

// Declare the type of item stored in the bag object. A typedef
// must precede #include "bag" (a better way is shown in Chapter 16).
// If you want a collection of strings, use the next line:
typedef string BAG_ELEMENT_TYPE;
#include "bag" // For a bag class that requires the previous typedef

int main()
{ // Test drive bag
  bag bagOfStrings(10);

  cout << "Empty? " << bagOfStrings.isEmpty() << endl;
  // Add four items
  bagOfStrings.add("A string");
  bagOfStrings.add("Another string");
  bagOfStrings.add("and still another");
  bagOfStrings.add("and a fourth");
  // Take one away
  // Send a remove message that doesn't find the argument
  if( bagOfStrings.remove("If I'm not in the bag, nothing happens") )
    cout << "remove successful" << endl;
  else
    cout << "string not found, bagOfStrings not changed" << endl;

  cout << "Empty? " << bagOfStrings.isEmpty() << endl;
  cout << "capacity is " << bagOfStrings.capacity() << endl;
  cout << "current size is " << bagOfStrings.size() << endl;
  
  return 0;
}
 