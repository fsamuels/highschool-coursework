#include <iostream.h>
#include "string"
#include "vector"

int main()
{
  vector <string> str(32);
  int n = 7;

  str[0] = "ABE";  // first == 0
  str[1] = "CLAY";
  str[2] = "KIM";
  str[3] = "LAU";  // mid == 3
  str[4] = "LISA"; 
  str[5] = "PELE";
  str[6] = "ROE";  // last == 6

  int first = 0;
  int mid;
  int last = n - 1; // last = 6;

  string searchString("LISA");
  while( (first <= last) )
  {
    mid = (first + last) / 2;     // (0 + 6) / 2 = 3
    if(searchString == str[mid])  // Check the three possibilities
      break;                      // 1) searchString is found
    else 
      if(searchString < str[mid]) // 2) It's in first half so
        last = mid - 1;           //    eliminate second half
      else                        // 3) It's in second half 
        first = mid + 1;          //    so eliminate first half
  }
  
  if(first <= last)
    cout << searchString << " found" << endl;
  else
    cout << searchString << " was not" << endl;

  return 0;
}