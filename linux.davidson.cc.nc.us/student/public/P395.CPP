#include "vector" // For the vector<CLASS> class
#include <iostream.h>

int main()
{
  int j, n;

  cout << "Enter vector capacity: ";
  cin >> n;
  vector <int> x(n);
  for(j = 0; j < n; j++)
  {
    x.at(j) = j;
  }
  cout << "First: " << x.at(0) << endl;
  cout << "Last: " << x.at(x.capacity() - 1) << endl;

  return 0;
}