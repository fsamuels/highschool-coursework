// Demonstrate what happens with bad input
#include <iostream> // For the cout and cin objects
using namespace std;

int main()
{
  int x = 0;
  
  cout << "Is cin good? " << cin.good() << endl;
  cout << "Enter either a good or bad int: ";
  cin >> x;
  cout << "Is cin still good? " << cin.good() << endl;
  
  return 0;
}