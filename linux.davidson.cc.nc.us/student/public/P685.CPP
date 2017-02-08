// Demonstrate that one bag can be assigned to another
#include <iostream.h>
typedef int BAG_ELEMENT_TYPE;
#include "bag" // Does not have a pointer data member; vector
// defines =

void show(const bag& b)
{
  for(b.first(); ! b.isDone(); b.next())
  {
    cout << b.currentItem() << " ";
  }
  cout << endl;
}

int main()
{
  bag b1;
  bag b2;
  for(int j = 0; j < 6; j++)
  {
    b1.add(j);
  }
  b2 = b1;
  // b2 is exactly like b1, because vector overloads = (assignment)
  cout << "b1: ";
  show(b1);
  cout << "b2: ";
  show(b2);
  cout << "This program runs fine.";
  
  return 0;
}
