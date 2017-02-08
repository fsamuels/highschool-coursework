/* Forrest Samuels

	March 22, 1999

	7i.cpp	

	csc 134

	This program will find a sales persons salary given 1500 base plus
5% of everything over 10000 in sales, $500 plus 8% of sales over 20,000
and base plus 1300 plus 12% of slaes over 30,000.

*/

#include <iostream>
using namespace std;
#include </student/public/compfun>

float salary(float sales)
{
	float pay = 1500.00;   //set up base salary

	if (sales <= 10000) {
		return pay;
	}
	else if(sales <= 20000) {
		pay = pay + ((sales - 10000.00) * .05);
	}
	else if(sales <= 30000) {
		pay = pay + (((sales - 20000.00) * .08) + 500.00);
	}
	else {
		pay = pay + (((sales - 30000.00) * .12) + 1300.00);
	}
	
	return pay;
}

void main()
{
	decimals(cout, 2);
	cout << salary(10000.00) << endl;
	cout << salary(10001.00) << endl;
	cout << salary(20000.00) << endl;
	cout << salary(20002.00) << endl;
	cout << salary(30000.00) << endl;
	cout << salary(30002.00) << endl;
}
