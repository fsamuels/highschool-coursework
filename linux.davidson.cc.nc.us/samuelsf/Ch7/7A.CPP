/* Forrest Samuels

	March 16, 1999

	7a.cpp

	csc 134

	This program will find gross pay and calculate overtime over 40hrs
worked.

*/

#include <iostream>
using namespace std;
#include </student/public/compfun>

float pay(float hrs, float rate)
{
	float pay;

	if (hrs > 40)
	{
		pay = 40.0 * rate;
		pay = pay + ((hrs - 40.0) * (rate * 1.5));
	}
	else
	{
		pay = hrs * rate;
	}

	return pay;
}

void main()
{
	decimals(cout, 2);
	cout << pay(38, 10.00) << endl;
	cout << pay(40, 10.00) << endl;
	cout << pay(42, 10.00) << endl;
	cout << pay(43, 10.00) << endl;
}
