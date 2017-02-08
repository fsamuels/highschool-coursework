#include <iostream.h>

#include "baccount"
typedef bankAccount BAG_ELEMENT_TYPE; // Assume bankAccount's available
#include "bag" // For a bag class that requires the previous typedef

int main()
{
  bag acct;

  acct.add( bankAccount("Jordy Gordon", 100.00) );
  acct.add( bankAccount("Hanna Helstrom", 200.00) );
  acct.add( bankAccount("Sammy Swanson", 300.00) );
  acct.add( bankAccount("Karly Kuprah", 400.00) );
  double assets = 0.0;
  for(acct.first(); ! acct.isDone(); acct.next())
  {
    assets = assets + acct.currentItem().balance();
  }
  cout << "Assets: " << assets << endl;

  acct.first();
  acct.next();
  cout << acct.currentItem().name() << endl;

  return 0;
}