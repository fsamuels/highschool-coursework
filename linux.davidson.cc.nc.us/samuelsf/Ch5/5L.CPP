/* Forrest Samuels		CSC 134

	3.2.99

	This program will output a bank account like shown in the book.
*/

#include </student/public/baccount>
#include <iostream>
#include </student/public/compfun>
using namespace std;

void display(const bankAccount & anAcct)
{
	string fullname, first, last;
	int space;
	decimals(cout, 2);
	fullname = anAcct.name();
	space = fullname.find(" ");
	first = fullname.substr(0, space);
	last = fullname.substr(space, 20);
	cout << "{ bankAccount: " << last << ", " <<
first << ", $" << anAcct.balance() << " }" << endl;

}

int main()
{
	bankAccount a("Annie Hill", 123.00);
	bankAccount b("Bob Becker", 45.60);
	display(a);
	display(b);
	return 0;
}
