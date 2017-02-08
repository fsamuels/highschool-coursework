#include "grid" // For the grid class

int main()
{
  grid aGrid(9, 7, 4, 2, east);

  aGrid.move(3);
  aGrid.turnLeft();
  aGrid.move(3);
  aGrid.turnLeft();
  aGrid.move(4);
  aGrid.turnLeft();
  aGrid.move(7);
  aGrid.display();

  return 0;
}
