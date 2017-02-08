// File name: test10oh.cpp
#include <fstream.h>
#include "string"
#include "stats"   // includes stats.h and stats.cpp
#include "compfun" // causeApause();

int main()
{
  string fileName;
  cout << "Enter file name: "; // Assume user will enter tests.dat
  cin >> fileName;  
  ifstream inFile( fileName.c_str() );
  double x(0.0);
  stats tests(24);

  while(inFile >> x)  
  {
     tests.add(x);
  }   

  cout << "Statistics for a set of tests"   << endl;
  cout << "     Size: " << tests.size()     << endl;
  cout << "     Mean: " << tests.mean()     << endl;
  cout << "     High: " << tests.max()      << endl;
  cout << "      Low: " << tests.min()      << endl;
  cout << "   Median: " << tests.median()   << endl;
  cout << " Variance: " << tests.variance() << endl;
  cout << "Stand Dev: " << tests.standardDeviation() << endl;

  tests.display();
  causeApause();
  return 0;
}
