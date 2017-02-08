// Count how many numbers are in a disk file. The ifstream object
// named is used as the input stream, not cin.
#include <fstream.h> // For the ifstream class
#include <iostream.h>

int main()
{
  ifstream inFile("numbers.dat");
  double x = 0.0; // Store file inputs here temporarily
  int n = 0;

  if( ! inFile )
  { // If true, the input file was not found
    cout << "Failed to find the file numbers.dat" << endl;
  }
  else
  {
    cout << "The file was successfully constructed" << endl;
    while( inFile >> x )
    {
      n++; // Track the number of loops
      cout << "iteration #" << n << ": " << x << endl;
    }
    cout << "End of file reached. " << n << " numbers found." << endl;
  }

  return 0;
}