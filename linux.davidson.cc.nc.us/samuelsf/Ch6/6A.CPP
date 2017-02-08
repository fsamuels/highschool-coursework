/* Forrest Samuels

CSC 134

March 3, 1999

This program will do some stuff with weeklyEmp.
*/

#include </student/public/weekemp>
#include <iostream>
using namespace std;
 

void main()
{
	weeklyEmp stuff("Samuels, Forrest", 40.0, 6.25, 0, "S");
	cout << "Gross Pay: " << stuff.grossPay() << endl;
	cout << "Income Tax: " << stuff.incomeTax() << endl;
}
