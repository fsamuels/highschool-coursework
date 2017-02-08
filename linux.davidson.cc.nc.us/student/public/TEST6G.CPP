// file name: test6g.cpp
#include "grid"
#include "compfun" // causeApause();

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

  causeApause();

  return 0;
}
