// file name: test18c.cpp
#include <iostream>
// using namespace std;
#include "track"
#include "genbag"
#include "compfun" // causeApause();

int main()
{
  track a("Shape of my Heart", 4*60+38, 4, 9);
  track b("Something the Boy Said", 5*60+28, 4, 10);
  bag <track> aBag;
  aBag.add(a);
  aBag.add(b);

  bag <track> anotherBag;
  anotherBag = aBag;
  cout << anotherBag.capacity() << endl; 

  track current;

  for(aBag.first(); ! aBag.isDone(); aBag.next() )
  {
    current = aBag.currentItem();
    cout << current.title() << endl;
  }

  causeApause();
  return 0;
}
