// Use for loops to set blocks around a grid of any size
#include "grid" // For the grid class

void setBorder(grid & g); // Avoid Metrowerks warning 

void setBorder(grid & g) // A change to g changes myGrid
{ // pre: The mover is not on an edge
  // post: The entire outside border is blocked
  int r, c;
  
  // It is useful that objects know things about themselves--number
  // of rows and columns for example, which vary from grid to grid
  for(r = 0; r < g.nRows(); r++)
  {
    g.block(r, 0); // Block west edge
    g.block(r, g.nColumns()-1); // Block east edge
  }

  // The first and last columns are blocked already so block
  // column #1 up to 1 less than the last column
  for(c = 1; c < g.nColumns() - 1; c++)
  {
    g.block(0, c); // Block most of the north edge
    g.block(g.nRows()-1, c); // Block most of the south edge
  }
}

int main()
{
  grid myGrid(8, 10, 1, 1, east);
  grid anotherGrid(3, 30, 1, 28, west);

  setBorder(myGrid);
  myGrid.display();
  cout << endl;
  setBorder(anotherGrid);
  anotherGrid.display();

  return 0;
}