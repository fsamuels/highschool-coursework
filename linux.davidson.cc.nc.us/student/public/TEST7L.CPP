// file name: tst7l.cpp  (that's 7ell, not 7one)
#include <iostream>  // for the cout object and endl
// using namespace std;
#include "grid"        // for a string class
#include "compfun" // causeApause();

// implement bool turnTillClear(grid & g) here

bool turnTillClear(grid & g)
{



}

int main()
{ // Test drive turnTillClear
  grid aGrid(6, 6, 4, 4, north);

  // Run this 5 times
  //   1)as is
  //   2)with first block commented out only
  //   3)with second block commented out only
  //   4)with thrird block commented out only
  //   5)with fourth block commented out only
  aGrid.block(3, 4);
  aGrid.block(4, 3);
  aGrid.block(5, 4);
  aGrid.block(4, 5);
  aGrid.display();
  cout << endl;

  if(! turnTillClear(aGrid))
  {
    cout << "mover is trapped" << endl;
  }
  else
  {
    cout << "mover can move forward" << endl;
  }

  aGrid.display();

  causeApause();

  return 0 ;
}

