/* Forrest Samuels	

	CSC 134HA

	7k.cpp

	March 23, 1999

	This here program will convert roman numerals into it's integer
value using the romanNumeral function that I create.
*/

#include <string>
#include <iostream>

string romanNumeral(char number)
{
	if (number == 'i' || number == 'I')
		return "1";
	if (number == 'v' || number == 'V')
		return "5";
	if (number == 'x' || number == 'X')
		return "10";
	if (number == 'l' || number == 'L')
		return "50";
	if (number == 'c' || number == 'C')
		return "100";
	if (number == 'd' || number == 'D')
		return "500";
	if (number == 'm' || number == 'M')
		return "1,000";
	else
		return "that isn't a a Roman Numeral!";
}
		
void main()
{
	cout << romanNumeral('i') << endl;
	cout << romanNumeral('I') << endl;
	cout << romanNumeral('v') << endl;
	cout << romanNumeral('V') << endl;
	cout << romanNumeral('x') << endl;
        cout << romanNumeral('X') << endl;
	cout << romanNumeral('l') << endl;
        cout << romanNumeral('L') << endl;
	cout << romanNumeral('c') << endl;
        cout << romanNumeral('C') << endl;
	cout << romanNumeral('d') << endl;
        cout << romanNumeral('D') << endl;
	cout << romanNumeral('m') << endl;
	cout << romanNumeral('M') << endl;
	cout << romanNumeral('q') << endl;
}
