#include <iostream>
// using namespace std;
// The file named "counter" is included on the disk
#include "counter"   // For class counter definition and member functions.
                     // You have to create both files.
#include "compfun" // causeApause();


int main()
{ // Test driver class counter 
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

  causeApause();
  
  return 0;
}
