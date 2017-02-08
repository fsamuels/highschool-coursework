// Call distance four times
#include <iostream.h> // For cout
#include <math.h>    // For sqrt and pow

double distance(double x1, double y1, double x2, double y2); // Avoid Codewarrior warning
double distance(double x1, double y1, double x2, double y2)
{ // post: Return the distance between any two points
  double result;
  result = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
  return result;
}

int main()
{ // Test drives the distance function
  cout << "(1.0, 1.0) (2.0, 2.0): " << distance(1.0, 1.0, 2.0, 2.0) << endl;
  cout << "(0.0, 0.0) (3.0, 4.0): " << distance(0.0, 0.0, 3.0, 4.0) << endl;
  cout << "(-5.7,2.5) (3.3,-4.7): " << distance(-5.7,2.5, 3.3,-4.7) << endl;
  cout << "(0.0, 0.0) (0.0, 0.0): " << distance(0.0, 0.0, 0.0, 0.0) << endl;

  return 0;
}