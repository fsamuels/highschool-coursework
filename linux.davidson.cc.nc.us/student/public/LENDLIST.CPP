// file lendlist.h
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#include "lendlist.h"  // for the lendable hierarchy
#include "compfun"

lendableList::lendableList()
{
  int pos;  // hold position of he pipe separator "|"

  my_size = 0;
  my_data.resize(sizeIncrement);  

  // format of book file uses | to separate data.
  // QA76.1|Rick Mercer|Computing Fundamentals with C++
  // QA76.2|Owen Astrachan|A Computer Science Tapestry 
  ifstream bookFile(bookFileName.c_str());

  string line, bookID, author, title;
  if(! bookFile)
  {
     cout << "Couldn't find the file of books" << endl;
     causeApause();
  }

  while( getline(bookFile, line) )
  {
    pos = line.find("|"); 
    bookID = line.substr(0, pos);
    line = line.substr(pos+1, line.length() );  // strip off ID
    pos = line.find("|"); 
    author = line.substr(0, pos);
    title = line.substr(pos+1, line.length() ); 
    addLendable(new book(bookID, author, title) );
  }

  // No get all videos. my_size is pointing the next available vector location

  string videoID;  // already have line and title
  ifstream videoFile(videoFileName.c_str());
  // format of video file uses | to separate data.
  // MGM1|The Magnificent Seven
  // Disney1|The Enchanted Mermaid

  if(! videoFile)
  {
    cout << "Couldn't find the file of videos" << endl;
    causeApause();
  }

  while( getline(videoFile, line) )
  {
    pos = line.find("|"); 
    videoID = line.substr(0, pos);
    title = line.substr(pos+1, line.length() );
    addLendable( new video (videoID, title) );
  }
}

void lendableList::addLendable(lendable* aLendable)
{
  if(my_size >= my_data.capacity())
   { // avoid running out of room and out of range subscripts
    my_data.resize(my_size + sizeIncrement);
  }
  my_data[my_size] = aLendable;
  my_size++;
}


bool lendableList::getLendable(string searchID, lendable* & lendPtr) const
{ 
  int subscript;
  string nextID;

  // Perform a sequential search
  for(subscript = 0; subscript < my_size; subscript++)
  { // search all items or break out of the loop when found
    nextID = my_data[subscript]->lendableID();
    if(nextID == searchID)
    { // found it
      break;
    }
  }
 
  if (subscript < my_size )
  { // found it
    lendPtr = my_data[subscript]; // assign pointer to lendPtr 
    return true;
  }
  else
  { // have to return something, so let it be the first.
    lendPtr = my_data[0]; // return a pointer to the first element that
    return false;         // hopefully will never be used by the client!
  }
}
