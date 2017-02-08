/*	Forrest Samuels

	CSC 134

	March 24, 1999

	7l.cpp	

	This program will use a bool function turnTillClear to determine
if a mover in the grid class can move. If it can not it will return false.
*/

#include <iostream>  
using namespace std;
#include "/student/public/grid"

bool turnTillClear(grid & g)
{
	if (g.frontIsClear())
		return true;
	else
		g.turnLeft();	
		
	if (g.frontIsClear())
		return true;
	else
		g.turnLeft();

	if (g.frontIsClear())
		return true;
	else
		g.turnLeft();

	if (g.frontIsClear())
		return true;
	else
		return false;
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

  return 0 ;
}


