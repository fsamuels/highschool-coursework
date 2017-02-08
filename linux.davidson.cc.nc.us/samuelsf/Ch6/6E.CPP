/* Forrest Samuels

CSC 134

March 15, 1999

This program will use bankAccount and keep track of of the number of
transactions, deposits, and withdrawls. 
*/

#include </student/csc134HA/samuelsf/Ch6/baccount>
#include <iostream>
using namespace std;
 

void main()
{
	bankAccount anAcct;

	cout << "transaction count = " << anAcct.transactionCount() <<
		endl;	
	anAcct.deposit(10.00);
	anAcct.deposit(20.00);
	anAcct.deposit(30.00);
	cout << "after three transactions: " << anAcct.transactionCount()
		<< endl;
	bankAccount another("Bob", 100.00);

	another.deposit(25.00);
	cout << "Should be 1: " << another.transactionCount() << endl;

}
