/* forrest samuels
	March 18, 1999
	CSC 134
	7d.cpp	
	This program will find the roots of a quadratic using the
quadraticEquation class that I write.
*/

#include <iostream>
using namespace std;
#include "/student/csc234/leonard/c++/quad" //include quad

int main()
{
  double a, b, c;

  cout << "enter three coefficients for equation ax^2 + bx + c:  1.0  0.0
-1.0 ";
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

  return 0;
}
