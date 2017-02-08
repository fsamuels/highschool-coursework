/* Forrest Samuels

CSC 134

March 10, 1999

This program will do some stuff with weeklyEmp dealing with raises and
overtime.
*/

#include </student/public/weekemp>
#include </student/public/compfun>
#include <iostream>
using namespace std;
 
void show(weeklyEmp stuff)
{
	decimals(cout, 2);
	cout.width(9);
	cout << stuff.grossPay();
	cout.width(12);
	cout << stuff.incomeTax() << endl;	
}


void main()
{
	weeklyEmp anEmp("name", 40.0, 10.0, 3, "M"); 

	cout << "Gross Pay  Income Tax" << endl;
	cout << "=========  ==========" << endl;
	show(anEmp);
	anEmp.set_rate(11.5);
	show(anEmp);
	anEmp.set_hours(42.0);
	show(anEmp);
}


