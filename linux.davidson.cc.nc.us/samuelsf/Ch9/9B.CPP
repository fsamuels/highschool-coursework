/*	Forrest Samuels
	
	csc 134

	9b.cpp

	April 22, 1999

	This program wil approximate the number of words in a file that
has the filename input by the user.
*/

#include <iostream>
using namespace std;
#include <fstream>
#include <string>

void main()
{
	string fileName, dummy;
	int n = 0;

	cout << "Enter a filename buddy: ";
	cin >> fileName;

	ifstream inFile(fileName.c_str());


	if(! inFile)
	{
	  	cout << "**Can't open the file " << fileName << endl;
	  	cout << "It can not be found" << endl;
	}
	else
	{
		while (inFile >> dummy)
		{
			n++;
		}

	cout << "There are about " << n; 
	cout << " words in the file " << fileName << endl;
}
}
