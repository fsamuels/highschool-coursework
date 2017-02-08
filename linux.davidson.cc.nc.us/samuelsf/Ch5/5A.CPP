/* Forrest Samuels	CSC 134

   2.22.99	

   This is just soem program out of the book that we were supposed to copy
so that we coud see a workign example of the use of user defined
functiuons.
*/

#include </student/public/compfun>
#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
	double result;
	result = sqrt(fabs(x - 0.3));
	return result;
}

double g(double x)
{
	double result;
	result = 2 * pow(x, 2.0);
	return result;
}

int main()
{
	decimals(cout, 5);
	cout.width(12);
	cout << f(3.0) << endl;
	cout.width(12);
	cout << g(16.0) << endl;
	cout.width(12);
	cout << f(100.0) + g(100.0) << endl;
	cout.width(12);
	cout << f(g(3.0)) << endl;
	cout.width(12);
	cout << g(f(3.0)) << endl;
	return 0;
}
