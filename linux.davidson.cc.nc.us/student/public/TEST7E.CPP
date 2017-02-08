#include <iostream>  // for cout
// using namespace std;
#include "grid"        // for class grid
#include "compfun"      // for causeApause();

bool moverOnCorner(const grid & g) 
{ // post: return true if the mover is on an edge or false otherwise
  bool result(false);

  result =    ( (g.row() == 0) && (g.column() == 0)              ) // upper left
           || ( (g.row() == 0) && (g.column() == g.nColumns()-1) ) // upper right
           || ( (g.row() == g.nRows()-1) && (g.column() == 0)      ) // lower left
           || ( (g.row() == g.nRows()-1) && (g.column() == g.nColumns()-1) ); // lower left
           
  return result;
}

void checkNow(const grid & g)
{
  g.display();
  if(moverOnCorner(g))
	  cout << "On corner at " << g.row() << ", " << g.column() << endl;
  else
	  cout << "Not" << endl;
  cout << endl;
}

int main()
{
  grid tarpit(3, 3, 0, 0, south);
  
  checkNow(tarpit);

  tarpit.move(1); 
  checkNow(tarpit);

  tarpit.move(1); 
  tarpit.turnLeft();
  checkNow(tarpit);

  tarpit.move(1); 
  checkNow(tarpit);
  
  // assert: the mover is in the middle of the bottom row facing east
  causeApause();

  tarpit.move(1); 
  tarpit.turnLeft();
  checkNow(tarpit);
  
  tarpit.move(1); 
  checkNow(tarpit);

  tarpit.move(1); 
  tarpit.turnLeft();
  checkNow(tarpit);

  // assert: the mover is in the upper right corner facing west
  causeApause();

  
  tarpit.move(1); 
  checkNow(tarpit);

  tarpit.turnLeft();
  tarpit.move(1); 
  checkNow(tarpit);
  // assert: every intersection of row and column have been tested

  causeApause();

  return 0;
}
