// Demonstrate capacity and resize
#include "vector" // For the vector<CLASS> class

int main()
{
  vector <int> v1(3, -999);
  vector <int> v2(500, 1);

  // assert: v2 stores 500 elements == 1
  v2 = v1;
  // assert: v2 now stores 3 elements == -999
  for(int j = 0; j < v2.capacity(); j++)
  {
    cout.width(5);
    cout << v2[j];
  }

  cout << v2[j+1];
  return 0;
}
