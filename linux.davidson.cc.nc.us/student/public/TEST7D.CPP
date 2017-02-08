// file name:  test7d.cpp
#include <iostream>
// using namespace std;
#include "quad"       // includes quad.h and quad.cpp
#include "compfun" // causeApause();

int main()
{
  double a, b, c;

  cout << "Enter a, b, and c like this:  1.0  0.0  -1.0 ";
  cin >> a >> b >> c;
  quadraticEquation qe(a, b, c);  

  qe.display();

  if( qe.hasRealRoots() )
  {
    cout << "roots for equation ";
    qe.display();
    cout << " are " << qe.root1() << " and " << qe.root2() << endl;
  }
  else
  {
    cout << "The eqaution ";
    qe.display();
    cout << "has no real roots for the coefficients given." << endl;
  }

  causeApause();

  return 0;
}
