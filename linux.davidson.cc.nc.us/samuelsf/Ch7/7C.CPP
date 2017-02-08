/* Forrest Samuels

	March 17, 1999
	7c.cpp
	csc134

	This program will use the quadratic formula to find roots or tell
you if there are no real roots.
*/

#include <iostream>
using namespace std;
#include </student/public/cmath>


bool roots(double a, double b, double c, double & root1, double & root2)
{ 
	double d;
	d = (b * b) - (4.0 * a * c);
	
	if (d < 0)
		return false;
	else
	{
	root1 = (-b - sqrt(d)) / (2 * a);
	root2 = (-b + sqrt(d)) / (2 * a);
	} 
	
		return true;

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
}
