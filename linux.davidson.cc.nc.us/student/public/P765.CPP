#include <iostream.h>

int mystery(int j, int k)
{
  if(j <= k)
    return 1;
  else
    return j + k + /* RP# MYST */ mystery(j - 1, k + 2);
}

int main()
{
  cout << "mystery(4, 2) = " << mystery(4, 2) << endl; // 7
  cout << "mystery(2, 4) = " << mystery(2, 4) << endl; // 1
  cout << "mystery(8, 1) = " << mystery(8, 1) << endl; // 31
  return 0;
}