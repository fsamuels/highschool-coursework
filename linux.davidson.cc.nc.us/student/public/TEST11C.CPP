// File name: test11c.cpp
#include <iostream>
// using namespace std;
#include "compfun" // causeApause();

#include "compfun" // For decimals
#include "baccount" // Must include baccount before the typedef

typedef bankAccount BAG_ELEMENT_TYPE;
#include "bag" // For the bag class

int main()
{
  bag account;

  account.add( bankAccount("Mellisa", 400) );
  account.add( bankAccount("Miguel", 200) );
  account.add( bankAccount("Bob", 300) );
  decimals(cout, 2);
//  account.sort();
  bankAccount anAcct;
  for( account.first(); ! account.isDone(); account.next() )
  {
    anAcct = account.currentItem();       // Output:
    cout.width(8);                        // 300.00 Bob
    cout << anAcct.balance();             // 400.00 Mellisa
    cout << " " << anAcct.name() << endl; // 200.00 Miguel
  }

  causeApause();

  return 0;
}