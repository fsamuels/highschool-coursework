/*	Forrest Samuels

	csc 134

	9c.cpp

	April 22, 1999

	This program will calculate payroll using data from an external
file.
*/

#include </student/public/compfun>
#include </student/public/weekemp>
#include <fstream>
#include <iostream>
using namespace std;  

void main()
{
	float hours, Rate, netPay;
	int exempt;
	string fName, lName, status, name;
	float totalHoursWorked = 0.0;
	float totalGrossPay = 0.0;
	float totalIncomeTax = 0.0;
	float totalFICATax = 0.0;
	float totalNetPay = 0.0;
	ifstream inFile("payroll.data");
	weeklyEmp anEmp;

/////////Set up table//////////
	decimals(cout, 2);

	cout.width(6);
	cout << "Pay";	
	cout.width(9);
	cout << "Hours";
	cout.width(9);
	cout << "Gross";
	cout.width(10);
	cout << "Income";
	cout.width(9);
	cout << "FICA";
	cout.width(11);
	cout << "Net";
	cout.width(3);
	cout << "   ";	
	cout << "Employee";
	cout << endl;
	cout.width(6);
        cout << "Rate";
        cout.width(9);
        cout << "Worked";
        cout.width(9);
        cout << "Pay";
        cout.width(10);
        cout << "Tax";
        cout.width(9);
        cout << "Tax";
	cout.width(11);
        cout << "Pay";
        cout.width(3);
        cout << "   ";
	cout << "Name";
        cout << endl;
	cout.width(6);
        cout << "======";
        cout.width(9);
        cout << "=====";
        cout.width(9);
        cout << "=====";
        cout.width(10);
        cout << "=======";
        cout.width(9);
        cout << "======";
        cout.width(11);
        cout << "=====";
	cout.width(3);
	cout << "   ";
	cout << "=======";
        cout << endl;
/////End of set up table//////

	while(inFile >> fName >> lName >> hours >> Rate >> 
		  exempt >> status)
	{

	  name = lName + ", " + fName;
	  
	  anEmp = weeklyEmp(name, hours, Rate, exempt, status); 
	
	  netPay = anEmp.grossPay() - ( anEmp.incomeTax() +
		   anEmp.FICATax() );

	  cout.width(6);
          cout << Rate;
          cout.width(9);
          cout << hours;
          cout.width(9);
          cout << anEmp.grossPay();
          cout.width(10);
          cout << anEmp.incomeTax();
          cout.width(9);
          cout << anEmp.FICATax();
          cout.width(11);
          cout << netPay;
	  cout.width(3);
	  cout << "   ";
      	  cout << anEmp.name();
	  cout << endl;

	  totalHoursWorked = totalHoursWorked + hours;
	  totalGrossPay = totalGrossPay + anEmp.grossPay();
	  totalIncomeTax = totalIncomeTax + anEmp.incomeTax();
	  totalFICATax = totalFICATax + anEmp.FICATax();
	  totalNetPay = totalNetPay + netPay;

	}

	cout.width(6);
        cout << " ";
        cout.width(9);
        cout << "-----";
        cout.width(9);
        cout << "-----";
        cout.width(10);
        cout << "-----";
        cout.width(9);
        cout << "-----";
        cout.width(11);
        cout << "-----";
	cout.width(3);
	cout << "   ";
        cout << endl;
	cout.width(6);
        cout << "Totals";
        cout.width(9);
        cout << totalHoursWorked;
        cout.width(9);
        cout << totalGrossPay;
        cout.width(10);
        cout << totalIncomeTax;
        cout.width(9);
        cout << totalFICATax;
        cout.width(11);
        cout << totalNetPay;
	cout.width(3);
	cout << "   ";
        cout << endl;

	
}

