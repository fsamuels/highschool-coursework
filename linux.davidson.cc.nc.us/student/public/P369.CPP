// Demonstrate capacity and resize
#include "vector" // For the vector<CLASS> class
#include <iostream.h>
#include "compfun" // for causeApause();

int main()
{
  int j;
  vector <int> v1(3, -999);
  vector <int> v2(100, 1);

  v2 = v1;
  // assert: v2 now stores 3 elements == -999
  for(j = 0; j < v2.capacity(); j++)
  {
    cout.width(5);
    cout << v2[j];
  }

  return 0;
}
