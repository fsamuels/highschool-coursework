// file name test8h.cpp
#include "elevator"  // includes elevator.h and elevator.cpp
#include "compfun" // causeApause();

int main()
{
  elevator aLift(1);
  aLift.select(5);
  aLift.select(3);

  causeApause();
  return 0;
}
