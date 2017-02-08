/*	Forrest Samuels
	
	csc 134

	April 23, 1999

	10b.cpp

	This program will use vectors to inpput some numbers, take the
average, and ouptput all numbers over average.

*/

#include <iostream>
using namespace std;
#include </student/public/vector>

void main()
{

	int a = 0;
	int n = 0;
	int number[100];

	cout << "Enter numbers or -1 to quit: " << endl;

while( (cin >> a) && (a != -1) )
{
	if (a != -1)
		{
		number[n] = a;
		n++;
		}
}

	cout << "Reversed:   ";	
	n--;  //fix because it starts at 0
	
while( n >= 0)
{
	cout << number[n] << "  ";
	n--;
}
	cout << endl;

}
