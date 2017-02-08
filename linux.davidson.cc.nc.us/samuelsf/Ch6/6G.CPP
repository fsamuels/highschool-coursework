/* Forrest Samuels

csc143HA

3-15-99

This progrma will do stuff with a grid after I add some cool things to the
grid class
*/


#include "/student/csc134HA/samuelsf/Ch6/grid"

int main()
{
  grid g(10, 10, 8, 8, north);
  
  g.display();
  g.move(5);
  g.turnAround();
  g.move(3);
  g.turnRight();
  g.move(6);
  g.display();

  return 0;
}

