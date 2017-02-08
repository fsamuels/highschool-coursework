#include <iostream>
//using namespace std;
#include "track"
#include "compfun"   // causeApause();

int main()
{ // test drive track
  track t1;
  track t2("I'm the Cat", 3*60+55, 5, 1);
  
  cout << t2.title() << endl;
  cout << t2.playTime() << " or " 
       << t2.playTime() / 60 << " minutes and " 
       << t2.playTime() % 60 << " seconds" << endl;
  cout << "track# " << t2.trackNumber() << endl;
  cout << "   CD# " << t2.cdNumber() << endl;

  causeApause();

  return 0;
}