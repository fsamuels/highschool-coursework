/* Forrest Samuels		CSC 134
*
*  Feburary 9, 1999
*
*  This program will play with bank accounts. It will do all kinds of math
*  but never get any user input.
*/

#include <iostream>
#include </student/public/baccount>
using namespace std;

void main()
{

	bankAccount one("Mellisa", 500.00);
	bankAccount theOther("Miguel", 500.00);
	
//Input Section

	
//Process Section

	one.deposit(123.45);
	theOther.deposit(50.00);
	one.withdraw(20.00);	
	theOther.withdraw(60.00);

//Output Section

	cout << one.name() << ": " << one.balance() << endl;
	cout << theOther.name() << ": " << theOther.balance() << endl;
	cout << "Combined: " << one.balance() + theOther.balance() <<endl;

}
