// Demonstrate capacity and resize
#include "vector"   // For the standard vector<CLASS> class

int main()
{
  vector <int> v1;  // v1 cannot store any elements
  vector <int> v2(5);
 
  cout << "v1 can hold " << v1.capacity() << endl;
  cout << "v2 can hold " << v2.capacity() << endl;
  v1.resize(22);
  cout << "v1 can now hold " << v1.capacity() << endl;

  return 0;
}