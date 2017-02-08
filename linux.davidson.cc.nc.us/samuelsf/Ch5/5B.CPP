/* Forrest Samuels		CSC 134

	2.22.99

	This program sums any three numbers by usig a user written
function.

*/

#include </student/public/compfun>
#include <iostream>
using namespace std;

double returnSum(double n1, double n2, double n3)
{
	return n1 + n2 + n3;
}

int main()
{
	decimals(cout, 1);
	cout << returnSum(1.1, 2.2, 3.3) << endl;
	cout << returnSum(-1, -2, 3) << endl;
	return 0;
}
