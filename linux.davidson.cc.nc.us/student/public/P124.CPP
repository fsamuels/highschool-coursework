// Access the state of a grid object with messages
#include <iostream.h>  // for the cout object
// using namespace std;
#include "grid"        // for class grid

int main()
{
  grid aGrid(7, 14, 5, 8, east);  // column 8 is the 9th column
  cout << "Current row      : " << aGrid.row()          << endl;
  cout << "Current column   : " << aGrid.column()       << endl;
  cout << "Number of rows   : " << aGrid.nRows()        << endl;
  cout << "Number of columns: " << aGrid.nColumns()     << endl;
  cout << "Front is clear?  : " << aGrid.frontIsClear() << endl;
  return 0;
}
