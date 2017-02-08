// Demonstrate iteration with pointers
#include <vector>   // For the standard vector class
#include <iostream.h> // For cout <<
// SKIP THIS UNLESS YOU HAVE A STANDARD COMPILER
// using namespace std;

int main()
{
  vector<int> x(5);

  x[0] = 11;
  x[1] = 22;
  x[2] = 33;
  x[3] = 44;
  x[4] = 55;
  // Don't need a variable 'n' to store the number of elements
  // Construct an iterator object named i

  vector<int>::iterator i;
  // assert: i can indirectly reference any vector<int> element
  cout << "*i x[j]" << endl;
  int j = 0;
  for(i = x.begin(); i != x.end(); i++)
  {
    cout << (*i) << " " << x[j] << endl;
    // i stores an address, *i refers to the element
    j++;
  }

  return 0;
}
