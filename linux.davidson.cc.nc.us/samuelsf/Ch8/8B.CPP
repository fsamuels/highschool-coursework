/*	Forrest Samuels
	
	CSC 134

	8b.cpp

	March 30, 1999

	This program will find factorials.
*/
#include <iostream>
using namespace std;

int factorial(int n)
{
	int a = 1, num = n;

	if (n == 0)
		return 1;
	else{
	
	while(a < n)
	{
		num = num * a;
		a++;
	}
}
	return num;
}

void main()
{
	cout << factorial(0) << endl;
	cout << factorial(1) << endl;
	cout << factorial(2) << endl;
	cout << factorial(7) << endl;
}
