#include <iostream>
// using namespace std;
#include "compfun" // causeApause();
 
#include "counter"   // for class counter definition and member functions

int main()
{ // Test driver class counter 
  counter aCounter(0, 4);  
  cout << "Current count: " << aCounter.count() << endl;   // 0
  aCounter.click();
  cout << "Current count: " << aCounter.count() << endl;   // 1
  aCounter.click();
  cout << "Current count: " << aCounter.count() << endl;   // 2
  aCounter.click();
  cout << "Current count: " << aCounter.count() << endl;   // 3
  aCounter.click();
  cout << "Current count: " << aCounter.count() << endl;   // 4
  aCounter.click();
  cout << "Current count: " << aCounter.count() << endl;   // 0
  aCounter.click();
  cout << "Current count: " << aCounter.count() << endl;   // 1

  causeApause();

  return 0;
}
