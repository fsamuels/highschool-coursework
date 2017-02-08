/*	Forrest Samuels
	
	csc 134

	April 23, 1999

	10a.cpp

	This program will use vectors to input and then outpus some
numbers in reverse order.

*/

#include <iostream>
using namespace std;

void main()
{

	int a = 0;
	int n = 0;
	int number[100];

	cout << "Enter up to 100 ints using -1 to quit: " << endl;

while( a != -1 && n < 99)
{
	cin >> a;
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
