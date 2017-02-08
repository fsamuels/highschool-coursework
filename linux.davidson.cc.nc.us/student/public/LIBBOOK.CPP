////////////////////////////////////////////////////////////
// IMPLEMENT class libraryBook MEMBER FUNCTIONS
////////////////////////////////////////////////////////////
#include "libbook.h"

//--default constructor
libraryBook::libraryBook()
{
  my_title = "?title?";
  my_author = "?author?";
  my_borrower = NOT_BORROWED_MESSAGE;
}

//--two argument constructor
libraryBook::libraryBook(string initTitle, string initAuthor)
{
  my_title = initTitle;
  my_author = initAuthor;
  my_borrower = NOT_BORROWED_MESSAGE;
}

// -- modifiers --

void libraryBook::borrowBook(string borrowersName)
{
  my_borrower = borrowersName;
}

void libraryBook::returnBook()
{
  my_borrower = NOT_BORROWED_MESSAGE;
}

//--accessors

string libraryBook::borrower() const
{
  return my_borrower;
}

// Operator functions needed for use with the STL
bool operator == (const libraryBook & left, const libraryBook & right)
{
  return left.my_author == right.my_author;
}

bool operator < (const libraryBook & left, const libraryBook & right)
{
  return left.my_author < right.my_author;
}


bool operator <= (const libraryBook & left, const libraryBook & right)
{
  return left.my_author <= right.my_author;
}

bool operator >= (const libraryBook & left, const libraryBook & right)
{
  return left.my_author >= right.my_author;
}

bool operator > (const libraryBook & left, const libraryBook & right)
{
  return left.my_author > right.my_author;
}

bool operator != (const libraryBook & left, const libraryBook & right)
{
  return left.my_author != right.my_author;
}

