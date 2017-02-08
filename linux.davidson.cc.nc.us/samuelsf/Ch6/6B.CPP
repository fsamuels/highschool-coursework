/* Forrest Samuels

CSC 134

March 9, 1999

This program will do some stuff with weeklyEmp.
*/

#include </student/public/weekemp>
#include </student/public/compfun>
#include <iostream>
using namespace std;
 

void main()
{
	string name, status;
	float rate, hours, netpay;
	int exemptions;

	cout << "Name: ";
	cin >> name;
	cout << "Hourly Rate: ";
	cin >> rate;
	cout << "Hours Worked: ";
	cin >> hours;
	cout << "Exemptions: ";
	cin >> exemptions;
	cout << "S)ingle M)arried: ";
	cin >> status;
	
	weeklyEmp stuff(name, hours, rate, exemptions, status);
	netpay = stuff.grossPay() - (stuff.incomeTax() + stuff.FICATax());	

	decimals(cout, 2);
	cout << "Employee: " << stuff.name() << endl;
	cout << "  Gross  Income    FICA      Net" << endl;
	cout << "    Pay     Tax     Tax      Pay" << endl;
	cout << "  =====  ======    ====      ===" << endl;
	cout.width(7);
	cout << stuff.grossPay();
	cout.width(8);
	cout << stuff.incomeTax();
	cout.width(8);
	cout << stuff.FICATax();
	cout.width(9);
	cout << netpay << endl;
 
}
