#include "vector" // For the vector<CLASS> class 3
#include "string" // For the string class

int main()
{
  int j;
  vector <double> x(8, 0.0);
  // assert: x has capacity to store 8 numbers. All are 0.0.

  // Assign new values to the first two elements of vector named x
  x[0] = 2.6;
  x[1] = 5.7;

  x[2] = x[0] + x[1]; // Store 8.3
  
  cout << "Enter two numbers: ";
  cin >> x[3] >> x[4];

  int n = 5;

  // Display the meaningful elements of x--the first n elements
  cout << "The first " << n << " elements of x: " << endl;
  for(j = 0; j < n; j++)
  {
	 cout << "x[" << j << "]: ";
	 cout << x[j] << endl;
  }

  // First set the largest as the first element . . .
  double largest = x[0];
  // . . . then compare all other vector elements x[1] through x[n-1]
  for(j = 1; j < n; j++)
  {
    if(x[j] > largest)
      largest = x[j];
  }
  // Display the largest
  cout << "The largest element in vector x = " << largest;

  return 0;
}