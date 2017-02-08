#include "vector" // For the vector<CLASS> class
#include <iostream.h>

void init( vector <int> & x, int & n );  // To avoid Metrowerks Codewariier warnings
void display(const vector <int> & x, int & n); 


void init( vector <int> & x, int & n ) // Two reference parameters
{ // post: Initialize the first n elements of the argument
  n = 5;
  x.resize(n);
  x[0] = 75;
  x[1] = 88;
  x[2] = 67;
  x[3] = 92;
  x[4] = 51;
  // assert: The arguments associated with x and n (test and n)
  // have been modified in main
}

void display(const vector <int> & x, int & n) // Const reference
{
  int j;
  // Display the vector with n meaningful values
  cout << "The vector: ";
  for( j = 0; j < n; j++ )
  {
    cout.width(5);
    cout << x[j] << " ";
  }
  cout << endl;
}

int main()
{
  vector <int> test(100, 0);
  int n;

  // Initialize test and n
  init( test, n );
  display( test, n );

  return 0;
}