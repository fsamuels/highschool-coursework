// File name: test10k.cpp   
#include <fstream> 
#include <iostream>
#include <string>
// using namespace std;
#include "compfun" // causeApause();


// stats include .h and .cpp fiels that don't exist yet
#include "stats" // includes stats.h and stats.cpp. You must write BOTH 
// YOU ARE ASKED TO WRITE stats.h AND stats.cpp

void show(const stats & tests) // Be sure this is const reference with & 
{
  cout << "Statistics for a set of tests"   << endl;
  cout << "     Size: " << tests.size()     << endl;
  cout << "     Mean: " << tests.mean()     << endl;
  cout << "     High: " << tests.max()      << endl;
  cout << "      Low: " << tests.min()      << endl;
  cout << "   Median: " << tests.median()   << endl;
  cout << " Variance: " << tests.variance() << endl;
  cout << "Stand Dev: " << tests.standardDeviation() << endl;
  tests.display();
}

int main()
{
  string fileName;
  cout << "Enter file name: "; // Assume user will enter tests.dat
  cin >> fileName;  
  ifstream inFile( fileName.c_str() );
  double x = 0.0;
  stats tests(24);

  while(inFile >> x)  
  {
     tests.add(x);
  }   

  show(tests);

  tests.add(100.00);
  tests.add( 40.5);

  show(tests);

  causeApause();
  
  return 0;
}
