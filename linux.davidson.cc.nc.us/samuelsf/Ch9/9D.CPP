/*	Forrest Samuels

	csc 134

	9d.cpp

	April 22, 1999

	This program will do the same as the one b4 except it will output
it to a file instead.

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
	ofstream outFile("payroll.rpt");
	weeklyEmp anEmp;

////////makes the pretty table////////
	decimals(cout, 2);

	outFile.width(6);
	outFile << "Pay";	
	outFile.width(9);
	outFile << "Hours";
	outFile.width(9);
	outFile << "Gross";
	outFile.width(10);
	outFile << "Income";
	outFile.width(9);
	outFile << "FICA";
	outFile.width(11);
	outFile << "Net";
	outFile.width(3);
	outFile << "   ";	
	outFile << "Employee";
	outFile << endl;
	outFile.width(6);
 	outFile << "Rate";
 	outFile.width(9);
 	outFile << "Worked";
 	outFile.width(9);
 	outFile << "Pay";
 	outFile.width(10);
 	outFile << "Tax";
      outFile.width(9);
      outFile << "Tax";
      outFile.width(11);
      outFile << "Pay";
      outFile.width(3);
      outFile << "   ";
      outFile << "Name";
      outFile << endl;
      outFile.width(6);
      outFile << "======";
      outFile.width(9);
      outFile << "=====";
      outFile.width(9);
      outFile << "=====";
      outFile.width(10);
      outFile << "=======";
      outFile.width(9);
      outFile << "======";
      outFile.width(11);
      outFile << "=====";
      outFile.width(3);
      outFile << "   ";
      outFile << "=======";
      outFile << endl;

	while(inFile >> fName >> lName >> hours >> Rate >> exempt >> 
			status)
{

	  name = lName + ", " + fName;
	  anEmp = weeklyEmp(name, hours, Rate, exempt, status); 
	  netPay = anEmp.grossPay() - ( anEmp.incomeTax() + 
			anEmp.FICATax() );

	outFile.width(6);
        outFile << Rate;
        outFile.width(9);
        outFile << hours;
        outFile.width(9);
        outFile << anEmp.grossPay();
        outFile.width(10);
        outFile << anEmp.incomeTax();
        outFile.width(9);
        outFile << anEmp.FICATax();
        outFile.width(11);
        outFile << netPay;
	outFile.width(3);
	outFile << "   ";
        outFile << anEmp.name();
	outFile << endl;

	  totalHoursWorked = totalHoursWorked + hours;
	  totalGrossPay = totalGrossPay + anEmp.grossPay();
	  totalIncomeTax = totalIncomeTax + anEmp.incomeTax();
	  totalFICATax = totalFICATax + anEmp.FICATax();
	  totalNetPay = totalNetPay + netPay;
}
	outFile.width(6);
        outFile << " ";
        outFile.width(9);
        outFile << "-----";
        outFile.width(9);
        outFile << "-----";
        outFile.width(10);
        outFile << "-----";
        outFile.width(9);
        outFile << "-----";
        outFile.width(11);
        outFile << "-----";
	outFile.width(3);
	outFile << "   ";
        outFile << endl;
	outFile.width(6);
        outFile << "Totals";
        outFile.width(9);
        outFile << totalHoursWorked;
        outFile.width(9);
        outFile << totalGrossPay;
        outFile.width(10);
        outFile << totalIncomeTax;
        outFile.width(9);
        outFile << totalFICATax;
        outFile.width(11);
        outFile << totalNetPay;
	outFile.width(3);
	outFile << "   ";
        outFile << endl;
}
