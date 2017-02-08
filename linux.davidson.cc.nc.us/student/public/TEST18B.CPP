// file name test18B.cpp
// Unless you overload < <= > >= != and ==, you will get many errors
#include <list>
#include <iostream>
using namespace std;  //In Borland 5.02, list needs std, which is correct
#include "compfun" // causeApause();
#include "track"

int main()
{
  list <track> aCD;
  list <track>::iterator i;

  aCD.push_back( track("Something the Boy Said" , 5*60+28, 4, 10) );
  aCD.push_back( track("Shape of my Heart" , 4*60+38, 4, 9) );
  aCD.sort();  // sorted by track numbers, the fourth argument 10 and 9
  for(i = aCD.begin(); i != aCD.end(); i++)
  {
    cout << (*i).title() << " " << (*i).trackNumber() <<  endl ;
  }

  causeApause();

  return 0;
}
