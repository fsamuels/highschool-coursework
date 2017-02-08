// file name: test7c.cpp
#include <iostream>
// using namespace std;
#include "compfun" // causeApause();


bool roots(double a, double b, double c, double & root1, double & root2)
{ // Implement roots here. Remember to return true or false in addition
  // to altering the last two arguments via reference (&) parameters.
  // ...
  // Complete the statements of function roots 
  // ...
}

int main()
{
  double a, b, c, root1, root2;
  
  cout << "Enter a, b, and c like this:  1.0  0.0  -1.0 ";
  cin >> a >> b >> c;
  if(roots(a, b, c, root1, root2))
	 cout << "roots: " << root1 << " and " << root2 << endl;
  else
  	 cout << "no real roots for the given coefficients" << endl;

  causeApause();
  return 0;
}
