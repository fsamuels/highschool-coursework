// file name: site.cpp
#include <fstream>   // for class ifstream
#include <string>   
using namespace std;
#include "compfun"   // for decimals(cout, 1)
#include "site.h"  // Allow for separate compilation

void site::reportHOV(string fileName)
{
  ifstream inFile(fileName.c_str());
  if(! inFile)
     cout << "**Error opening input file '" << fileName << "'\n";
  
  // If the file is not opened, the report is meaningless
  int nRows = 3;
  int nCols = 8;
  int siteNumber;
  string date;
  inFile >> siteNumber;
  inFile >> date;
  // Incomplete: read the tabular data from inFile.
  // Note: the matrix object name is my_humanData
  // --->
  // --->
  // --->

  decimals(cout, 1);
  cout << "Site #" << siteNumber << endl;
  cout << date << endl;
  cout << "ESTIMATES OF HUMAN-OBSERVED VISIBILITY\n" << endl;
  cout << "        8:00  9:00 10:00 11:00 12:00 13:00 14:00 15:00" << endl;
  cout << "Path +-------------------------------------------------+" << endl;
  // YOU COMPLETE: Display the matrix object my_humanData
  // using six columns for each human estimate of visibility
  // --->
  // --->
  // --->

  // YOU COMPLETE: Compute and output statistics for one day:
  // --->
  // --->
  // --->
}

