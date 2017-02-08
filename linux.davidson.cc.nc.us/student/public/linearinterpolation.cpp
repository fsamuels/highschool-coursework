#include "vector"
#include <ctype.h>  // for toupper
 
int main()
{
  // Initialize rpm, torque, and n
	char answer;
	vector <double> rpm(25);
	vector <double> torque(25);
	rpm[0] = 0;   torque[0] = 0;
    // ...
	rpm[13] = 6500;   torque[13] = 211;
    int n = 14;

	do
	{
  // get theRpm

  // if theRpm < rpm[0] or theRpm > rpm[n-1]  
  //	 say out of range
  // else
  //     find j such that theRpm >= rpm[j] && theRpm <= rpm[j+1] 
  //     compute theTorque = torque[j] + ( ... ) / () * ( )

 //
      cout << "Another <y/n>: ";
	  cin >> answer;
	  answer = toupper(answer);
	} while (answer != 'N');
 

  return 0;
}

