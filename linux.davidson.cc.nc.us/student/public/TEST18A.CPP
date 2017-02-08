// file name test18A.cpp
#include "track"
#include <iostream>
#include "compfun" // causeApause();

int main()
{
  track a("Shape of my Heart" , 4*60+38, 4, 9);
  track b("Something the Boy Said" , 5*60+28, 4, 10);

  if (a < b)
     cout << "a < b" << endl;
  if ( a == b)
    cout << "a == b" << endl;

  causeApause();
  return 0;
}
