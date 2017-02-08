#include <iostream.h>

typedef int BAG_ELEMENT_TYPE;
#include "bag" // For the bag class

int main()
{
  bag aBagOfInts;

  // Add 12 integers to aBagOfInts
  int n = 12;
  for(int j = 1; j <= n; j++)
  {
    aBagOfInts.add(j);
  }

  cout << "\nTraverse the entire collection:" << endl;
  cout << "\nThe bag: ";
  aBagOfInts.first();

  while ( ! aBagOfInts.isDone() )
  {
    cout << aBagOfInts.currentItem() << " ";
    aBagOfInts.next(); // Move to the next (or end)
  }

  return 0;
}
