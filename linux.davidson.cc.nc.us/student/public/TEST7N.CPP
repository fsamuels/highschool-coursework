// file name: test7n.cpp
#include <iostream>
#include <string>
// using namespace std;
#include "weekemp"
#include "compfun"

void display(const weeklyEmp & e)
{
  cout.width(8);
  cout << e.grossPay();
  cout.width(8);
  cout << e.incomeTax();
  cout << "    ";
  cout << e.name() << endl;
}

int main()
{
  decimals(cout, 2);

  cout << "Single: " << endl;
  weeklyEmp ian( "ian", 1, 49.00, 0, "S");
  weeklyEmp frank( "frank", 1, 50.00, 0, "S");
  weeklyEmp oscar( "oscar", 1, 451.00, 0, "S");
  weeklyEmp george( "george", 1, 452.00, 0, "S");
  weeklyEmp mary( "mary", 1, 942.00, 0, "S");
  weeklyEmp jane( "jane", 1, 943.00, 0, "S");
  
  display(ian);
  display(frank);
  display(oscar);
  display(george);
  display(mary);
  display(jane);

  cout << endl << "Married" << endl;
  
  weeklyEmp bob( "bob", 1, 119.00, 0, "M");
  weeklyEmp sam( "sam", 1, 120.00, 0, "M");
  weeklyEmp mike( "mike", 1, 784.00, 0, "M");
  weeklyEmp ryan( "ryan", 1, 785.00, 0, "M");
  weeklyEmp joe( "joe", 1, 1563.00, 0, "M");
  weeklyEmp sherry( "sherry", 1, 1564.00, 0, "M");

  display(bob);
  display(sam);
  display(mike);
  display(ryan);
  display(joe);
  display(sherry);
  cout << endl;

  weeklyEmp bobbie( "Single with 2 exemptions", 40, 15.00, 2, "S");
  weeklyEmp sammie( "Married with 2 exemptions", 40, 15.00, 2, "M");
  weeklyEmp mickey( "Should not be negative tax", 3, 15.00, 2, "S");
  weeklyEmp mickey2( "You should carefully check for minus tax possiblility",
                      50, 15.00, 10, "S");
  
  display(bobbie);
  display(sammie);
  display(mickey);
  display(mickey2);
 
  causeApause();
  
  return 0;
}
