/*	Forrest Samuels

	csc 134

	April 16, 1999

	8j.cpp

	This program will do some stuff with a table of exponents.
*/

#include <iostream>
using namespace std;
#include <cmath>
#include </student/public/compfun>

void main()
{
int low = -1;
int high = -1;

////////////// Enter low exponent //////////
while (low < 0 || low > 20)
{
	cout << "Enter low exponent from 0 to 20: ";
	cin >> low;
	if(low < 0 || low > 20)
		cout << "                       Try again" << endl;
}

////////////// Enter high exponent /////////
while (high < low || high > 20)
{
	cout << "Enter high exponent from " << low << " to 20: ";
	cin >> high;
	if(high < low || high > 20)
		cout << "                       Try again" << endl;
}

///////////// Exponent outputer thingy ///////
	cout.width(2);
	cout << "X";
	cout.width(11);
	cout << "2^X" << endl;
	cout.width(2);
	cout << "==";
	cout.width(11);
	cout << "======" << endl;

while ( low <= high )
{
	cout.width(2);
	cout << low;
	cout.width(11);
	cout << pow(2, low) << endl;
	low++;
}

}
