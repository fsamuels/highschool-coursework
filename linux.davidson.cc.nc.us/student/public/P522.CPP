// Interchange two pointer values. The pointers are switched to
// point to the other's original int object.
#include <iostream.h>

int main()
{
  double* p1;
  double* p2;
  double* temp;
  double n1 = 99.9;
  double n2 = 88.8;

  // Let p1 point to n1 and p2 point to n2
  p1 = &n1;
  p2 = &n2;
  cout << "*p1 and *p2 before switch" << endl;
  cout << (*p1) << " " << (*p2) << endl;

  // Swap the pointers by letting p1 point to where p2 is pointing
  // and letting p2 point to where p1 is pointing
  temp = p1;
  p1 = p2;
  p2 = temp;
  // Now the values of the pointers are switched to point to each
  // other's int object. The ints themselves do not move.
  cout << "*p1 and *p2 after switch" << endl;
  cout << (*p1) << " " << (*p2) << endl;

  return 0;
}