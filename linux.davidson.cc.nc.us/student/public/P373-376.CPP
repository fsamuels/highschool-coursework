// Initialize and show the first n elements of vector named name
#include <iostream.h>
#include "string"
#include "vector" // For the vector<CLASS> class

int main()
{
  int j, n;
  vector <string> myFriends(10);
  // assert: All of myFriends are the default null string ""

  n = 5; // Set the number of meaningful elements to be searched
  myFriends[0] = "DEBBIE";
  myFriends[1] = "JOEY";
  myFriends[2] = "BOBBIE";
  myFriends[3] = "SUSIE";
  myFriends[4] = "MIKEY";
  // Just show the vector elements for now
  for(j = 0; j < n; j++)
  {
    cout << "myFriends[" << j << "]: " << myFriends[j] << endl;
  }

  // Get a name to search for
  string searchName;
  cout << "Enter existing name to search for [UPPERCASE]: ";
  cin >> searchName;
  // assert: searchName is in myFriends--if it is not, watch out!
  // Search for searchName starting at myFriends[0]
  int subscript = 0;
  while( (subscript < n) && (searchName != myFriends[subscript]) )
  { // assert: searchName has not yet been found
    subscript++; // Prepare to compare searchName to next element
  }

  // Report success or failure (see changes below)
  if(subscript < n)
    cout << myFriends[subscript] << " found at subscript " << subscript << endl;
  else
    cout << searchName << " not found" << endl;

  return 0;
}