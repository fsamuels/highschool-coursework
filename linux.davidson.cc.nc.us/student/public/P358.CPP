#include <iostream.h> // For cout
#include <fstream.h>  // For the ofstream class
#include "compfun"  // For decimals(outFile, 3);

int main()
{
  ofstream outFile("out.dat");
  outFile << "This string goes to a disk file, not the screen" << endl;
  double x = 1.23456789;

  outFile << x << endl; // Write x to a disk file in default format
  decimals(outFile, 3); // Change the state of outFile

  outFile << x << endl; // Write x to disk file with 3 decimal places
  outFile.width(30);    // Write a width message to outFile

  outFile << x << endl; // Write x to a disk file in 30 columns
  cout << "This string goes to the screen" << endl;

  return 0;
}