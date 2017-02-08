/* Forrest Samuels		CSC 134

	2.23.99

	This program returns the middle three characters of any string.

*/

#include <string>
#include <iostream>
using namespace std;

string middleThree(string s1)
{
	int spos;
	spos = (s1.length() / 2)-1; 
	s1 = s1.substr(spos, 3);	
	return s1; 

}

int main()
{
	cout << middleThree("Rob") << endl;
	cout << middleThree("Roby") << endl;
	cout << middleThree("Robie") << endl;
	cout << middleThree("Robbie") << endl;
	cout << middleThree("Roberto") << endl;

	return 0;
}
