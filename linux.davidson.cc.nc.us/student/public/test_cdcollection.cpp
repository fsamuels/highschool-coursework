#include <iostream.h>
// using namespace std;
#include "cdcollec"
#include "compfun"

int main()
{ // test drive cdCollection
  cdCollection theCdCollection;
  CD aCD;

  // Iterate over all CDs in the cdCollection, just show artist and title
  theCdCollection.first();
  while( ! theCdCollection.isDone() )
  {
    aCD = theCdCollection.currentItem();
    




cout << "1" << aCD.artist() << "2" << endl;
cout << "3" << aCD.title() << "4" << endl;







   










    theCdCollection.next();
  }



  return 0;
}
