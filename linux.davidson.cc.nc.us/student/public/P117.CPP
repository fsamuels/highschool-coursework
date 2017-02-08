#include <iostream.h> // For the ostream class (and cout)

int main()
{
  cout << 1;
  cout.width(5);
  cout << 2;
  // assert: 2 appears right-justified in five columns following 1

  return 0;
}