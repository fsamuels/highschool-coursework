#include "vector"        // for class vector<CLASS>

#include "iostream"
#include "string"
using namespace std;
#include "compfun" // causeApause();

// implement int search 

// implement void init

// implement void display

int main()
{
  vector <string> name(10);
  int n;

  // Initialize name and n
  init( name, n);
  display( name, n );
  
  int j;
  // Search for every name in the vector. 
  for(j = 0; j < n; j++)
  {
     cout << name[j] << " has index " << search(name, name[j], n) << endl;
  }

  // Search for a few that probably aren't there
  // pre: n >= 4
  cout << "'NOT HERE' has index " << search(name, "NOT HERE", n) << endl;
  cout << "'XYZABC!!' has index " << search(name, "XYZABC!!", n) << endl;

  causeApause();
  return 0;
}
