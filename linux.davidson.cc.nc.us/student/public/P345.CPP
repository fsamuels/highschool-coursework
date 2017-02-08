// Include fstream for I/O streams dealing with disk files
#include <fstream.h> // For the ifstream class
#include <iostream.h> // For cout

int main()
{
  int n1, n2, n3;
  // Initialize an ifstream object so inFile is an input stream
  // associated with the operating system file named input.dat
  ifstream inFile("input.dat");
  // Extract three integers from the file input.dat
  inFile >> n1 >> n2 >> n3;
  cout << "n1: " << n1 << endl;
  cout << "n2: " << n2 << endl;
  cout << "n3: " << n3 << endl;

  return 0;
}