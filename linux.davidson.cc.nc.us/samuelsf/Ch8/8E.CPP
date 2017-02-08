/*	Forrest Samuels

	CSC 134

	April 12, 1999

	8e.cpp	

	This program will use an indeterminate loop to input a range of
numbers and determine the lowest, highest, and average of the numbers.

*/

#include <iostream>
using namespace std;

  float wspeed, average;
  float highest = -9999; // No wind speed will be less than -9999
  float lowest = 9999;   // No wind speed will be greater than 9999
  float total = 0.0;
  float n = 0.0;

void main()
{
    cout << "Enter wind speed readings or a number < 0 to quit: " << endl;
    cin >> wspeed;

while(wspeed >= 0.0)
{
  total = total + wspeed;
    if(wspeed > highest)
      highest = wspeed;
    if(wspeed < lowest)
      lowest = wspeed;
	
	n++;
	cin >> wspeed;
}
	average = total / n;

cout << "   n: " << n << endl;
cout << "High: " << highest << endl;
cout << " Low: " << lowest << endl;
cout << " Ave: " << average << endl;

}
