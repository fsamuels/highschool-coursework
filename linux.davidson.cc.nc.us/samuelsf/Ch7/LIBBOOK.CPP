////////////////////////////////////////////////////////////
// IMPLEMENT class libraryBook MEMBER FUNCTIONS
////////////////////////////////////////////////////////////
#include "/student/csc234/leonard/c++/libbook.h"

//--default constructor
libraryBook::libraryBook()
{
  my_title = "?title?";
  my_author = "?author?";
  my_borrower = NOT_BORROWED_MESSAGE;
	my_availability = true; //sets up book as not checked out at start
}

//--two argument constructor
libraryBook::libraryBook(string initTitle, string initAuthor)
{
  my_title = initTitle;
  my_author = initAuthor;
  my_borrower = NOT_BORROWED_MESSAGE;
	my_availability = true; //sets up as not checked out at start
}

// -- modifiers --

void libraryBook::borrowBook(string borrowersName)
{
	my_availability = false; //makes book checked out
  my_borrower = borrowersName;
}

void libraryBook::returnBook()
{
	my_availability = true; //makes book not checked out 
  my_borrower = NOT_BORROWED_MESSAGE;
}

//--accessors

string libraryBook::borrower() const
{
  return my_borrower;
}

/////////////////////additions by forrest////////////
bool libraryBook::isAvailable() const
{
	return my_availability;
}
///////////////////end additions//////////////////////

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

