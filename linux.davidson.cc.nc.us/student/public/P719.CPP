#include <iostream.h>
#include "matrix" // For the matrix class

int main()
{
  matrix<int> table(5, 8, 0);
  table[0][0] = 53;
  table[1][1] = 64;
  table[2][2] = 75;
  table[3][3] = 86;
  table[4][4] = 97;
  table[4][5] = 106;
  table[4][6] = 117;
  table[4][7] = 128;
  table[0][7] = -1;
  for(int row = 0; row < 5; row++)
  { // Display one row
    for(int col = 0; col < 8; col++)
    { // Display each column of the row
      cout.width(6);
      cout << table[row][col];
    }
    cout << endl;
  }

  return 0;
}
