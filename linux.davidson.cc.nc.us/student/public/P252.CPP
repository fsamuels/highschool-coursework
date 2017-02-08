// Show a more complex logical expression inside a bool function
#include <iostream.h> // For cout
#include "grid" // For the grid class
bool moverOnEdge(const grid & g); // Avoif Codewarrier warning

bool moverOnEdge(const grid & g)
{ // post: Return true if the mover is on an edge or false otherwise
  bool result = false;

  result =    (g.row() == 0)                  // On north edge?
           || (g.row() == g.nRows()-1)        // On south edge?
           || (g.column() == 0)               // On west edge?
           || (g.column() == g.nColumns()-1); // On east edge?

  return result;
}

int main()
{ // Test drive moverOnEdge
  grid tarpit(6, 6, 2, 5, east);
  if(moverOnEdge(tarpit))
  {
    cout << "On edge" << endl;
  }
  else
  {
    cout << "Not" << endl;
  }
  
  return 0;
}
