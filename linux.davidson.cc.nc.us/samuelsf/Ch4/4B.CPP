/* Forrest Samuels		CSC 134
*
*  Feburary 8, 1999
*
*  This program will take the input of a name in the form of
*  Last, First I. and output it as First I. Last.
*/

#include <iostream>
#include <string>
using namespace std;

void main()
{
	string first, middle, last;
	int slength;

//Input Section

	cout << "Enter name as Last, First I. ";
	cin >> last >> first >> middle;

//Process Section

	slength = last.length();
	last = last.substr(0, (slength-1));
	
//Output Section

	cout << first << " "<< middle << " " << last << endl;

}
