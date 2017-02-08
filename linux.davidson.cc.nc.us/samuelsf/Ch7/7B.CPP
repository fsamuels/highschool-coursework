/* Forrest Samuels

	March 17, 1999

	7b.cpp	

	csc 134

	This program will find a sales persons salary given 1500 base plus
5% of everything over 10000 in sales.

*/

#include <iostream>
using namespace std;
#include </student/public/compfun>

float salary(float sales)
{
	float pay = 1500.00;   //set up base salary

	if (sales > 10000)
	{
		pay = pay + ((sales - 10000) * .05);
	}
	else

	return pay;
}

void main()
{
	decimals(cout, 2);
	cout << salary(9999.99) << endl;
	cout << salary(10001.00) << endl;
	cout << salary(10202.00) << endl;
	cout << salary(15000.00) << endl;
}
