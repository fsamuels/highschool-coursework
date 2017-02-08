/*	Forrest Samuels	

	CSC 134

	March 31, 1999

	8d.cpp

	This program will find the future value of an investment copunded
annualy, monthly, and daily.

*/

#include <iostream>
using namespace std;
#include </student/public/compfun>   //for width, etc... 

void futureValue(float principal, float iRate)
{
	float annual, monthly, daily; 
	iRate = (iRate / 100.0);   //makes iRate a useable number, not a % 
	float mRate = (iRate / 12.0) + 1;
	float dRate = (iRate / 365.0) + 1;
	int d;

	annual = principal * (iRate + 1.0);
	
	monthly = principal;
	for (d = 1; d <= 12; d++)
	{
		monthly = monthly * mRate;
	}
		
	daily = principal;
	for (d = 1; d <= 365; d++)
	{	
		daily = daily * dRate;
	}

cout << "              Annual      Monthly     Daily" << endl;
cout << "FutureValue:";
decimals(cout,2);
cout.width(9);
	cout << annual;
cout.width(12);
	cout << monthly;
cout.width(12);	
	cout << daily << endl;

}

void main()
{
	float p, i;	

	cout << "Enter principal : ";
	cin >> p;
	cout << "Enter annual interest rate [0...25] : ";
	cin >> i;

	futureValue(p, i);
}
