/*	Forrest Samuels

	csc 134

	April 22, 1999

	9a.cpp

	This here program will determine the lowest, highest, and wverage
of a set of wind speed readings from a file. 
*/

#include <iostream>
using namespace std;
#include <fstream>

  int wspeed;
  float average;
  int highest = -9999; // No wind speed will be less than -9999
  int lowest = 9999;   // No wind speed will be greater than 9999
  float total = 0.0;
  int n = 0;

void main()
{

    ifstream inFile("wind.dat");    
    
while(inFile >> wspeed)
{
  total = total + wspeed;
    if(wspeed > highest)
      highest = wspeed;
    if(wspeed < lowest)
      lowest = wspeed;
	
	n++;
}
	average = total / n;

cout << "   n: " << n << endl;
cout << "High: " << highest << endl;
cout << " Low: " << lowest << endl;
cout << " Ave: " << average << endl;

}
