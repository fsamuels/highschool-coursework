
// File name: test7m.cpp
#include <fstream.h> 
#include "string"
#include "stats"   // includes stats.h and stats.cpp
#include "compfun" // causeApause();

int main()
{
  string fileName;
  cout << "Enter file name: ";   // Enter tests.dat
  cin >> fileName;  
  ifstream inFile(fileName.c_str(), ios::nocreate);
  double x(0.0);
  stats tests;
  while (inFile >> x)
  {
     tests.add(x);
  }   

  cout << "Statistics for a set of tests"   << endl;
  cout << "     Size: " << tests.size()     << endl;
  cout << "     Mean: " << tests.mean()     << endl;
  cout << "     High: " << tests.high()     << endl;
  cout << "      Low: " << tests.low()      << endl;
  cout << "   Median: " << tests.median()   << endl;
  cout << " Variance: " << tests.variance() << endl;
  cout << "Stand Dev: " << tests.standardDeviation() << endl;

  tests.display();

  causeApause();

  return 0;
}
