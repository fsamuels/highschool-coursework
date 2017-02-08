/*	Forrest Samuels

	csc 134

	April 13, 1999

	8i.cpp

	This program will work like a mini teller.
*/

#include <iostream>
using namespace std;
#include </student/public/baccount>
#include </student/public/string>
#include <ctype.h>

	string name;
        float balance, w_amt, d_amt;
        char choice;

//Functions

char nextOption()
{
        char option = '?';
        do {
                cout << "W)ithdrawl, D)eposit, or Q)uit: ";
                cin >> option;
                option = toupper(option);
        } while((option != 'W') && (option != 'D') && (option != 'Q'));
                return option;
}

void withdraw(bankAccount & mine)
{
	cout << "Enter withdraw amount: ";
	cin >> w_amt;

	if (w_amt > mine.balance())
		cout << "**Amount requested exceeds account balance**" <<
			endl;
	else
		mine.withdraw(w_amt); 
}               

void deposit(bankAccount & mine)
{
        cout << "Enter deposit amount: ";
	cin >> d_amt;

	mine.deposit(d_amt);
}
      
//end of functions

void main()
{

cout << "Enter customer name: ";
cin >> name;
cout << "Enter initial balance: ";
cin >> balance;

bankAccount mine(name, balance);

  do {
	choice = nextOption();
    if('W' == choice)
      withdraw(mine);
    if('D' == choice)
      deposit(mine);
  } while (choice != 'Q');

cout << "Ending balance: " << mine.balance() << endl;
}




 
