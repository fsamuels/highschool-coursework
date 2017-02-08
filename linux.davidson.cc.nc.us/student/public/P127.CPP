// This program sets two cookies on the table and instructs a kid
// on how to locate them, "eat" them, and return home
#include "grid" // For the grid class

int main()
{
  grid kid(8, 12, 0, 0, south);

  kid.putDown(4, 0);
  kid.putDown(4, 3);
  kid.block(3, 2);
  kid.block(4, 2);
  kid.block(5, 2);
  // Show the state of kid
  kid.display();
  // "Eat" two cookies
  kid.move(4);
  kid.pickUp();
  kid.move(2);
  kid.turnLeft();
  kid.move(3);
  kid.turnLeft();
  kid.move(2);
  kid.pickUp();

  // Get the kid back home
  kid.move(4);
  kid.turnLeft();
  kid.move(3);
  // Show the ending state
  kid.display();

  return 0;
}
