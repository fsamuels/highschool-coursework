//Forrest samuels
//csc134HA
//3-15-99
//this prgram reguires me to write a header and cpp fiel fro a class
//called couter and use it to count stuff like a car odometer.


#include <iostream>
using namespace std;
#include "/student/csc134HA/samuelsf/Ch6/counter"


int main()
{
  counter aCounter(0, 3);  
  cout << aCounter.count() << endl;   // 0
  aCounter.click();
  cout << aCounter.count() << endl;   // 1
  aCounter.click();
  cout << aCounter.count() << endl;   // 2
  aCounter.click();
  cout << aCounter.count() << endl;   // 3
  aCounter.click();
  cout << aCounter.count() << endl;   // 0
  aCounter.click();
  cout << aCounter.count() << endl;   // 1
  aCounter.reset();
  cout << aCounter.count() << endl;   // 0

  return 0;
}

