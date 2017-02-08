/* Forrest Samuels		CSC 134
*
*  Feburary 10, 1999
*
*  This program will initalize a banck account and allow a deposit and
*  withdraw from user input.
*/

#include "/student/public/baccount"
using namespace std;

void main()
{
	string name;
	float balance, deposit, withdraw;

//Input Section

	cout << "Enter a bank account holder's name: ";
	cin >> name;
	cout << "Enter starting balance: ";
	cin >> balance;
	cout << "Enter ammount to deposit: ";
	cin >> deposit;
	cout << "Enter ammount to withdraw: ";
	cin >> withdraw;
	
//Process Section

	bankAccount account(name, balance);
	account.deposit(deposit);
	account.withdraw(withdraw);

//Output Section

	cout << account.name() << "'s balance: " << account.balance() <<
endl;
}
