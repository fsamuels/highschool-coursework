//--------------------------------------------------------
// file name: libbook.h
//
// defines: class libraryBook
//--------------------------------------------------------
#ifndef LIBBOOK_H
#define LIBBOOK_H
#include <string>
using namespace std;

const string NOT_BORROWED_MESSAGE = "not currently borrowed";

class libraryBook {
public:
//--constructors
   libraryBook();
   // post: create a default libraryBook object

   libraryBook(string initTitle, string initAuthor);
   // post: Initialize a libraryBook object as follows:
   //       1. The author and title are set
   //       2. The borrower becomes "not currently borrowed"
   // ex:      libraryBook aBook("Patriot Games", "Tom Clancy");

//--modifiers
   void borrowBook(string borrowersName);
   // post: Records the borrowers name
   // ex:   aBook.borrowBook("Wilma Riveria");

   void returnBook();
   // post: The book becomes available as the becomes "not currently borrowed"
   // ex:   aBook.returnBook();

//--accessors
   string borrower() const;
   // post: returns "not currently borrowed" if the book is available
   //       or the borrower's name if the book is checked out.
   // ex:   cout << aBook.borrower();

//////////////Additions by Forrest///////////////
	string author() const;

	string title() const;
/////////////////////////////////////////////////

//--operator functions for use with the STL
friend bool operator == (const libraryBook&, const libraryBook&);
friend bool operator <  (const libraryBook&, const libraryBook&);
friend bool operator > (const libraryBook&, const libraryBook&);
friend bool operator <= (const libraryBook&, const libraryBook&);
friend bool operator >= (const libraryBook&, const libraryBook&);
friend bool operator != (const libraryBook&, const libraryBook&);

private:
   string my_author;
   string my_title;
   string my_borrower;
};

#endif   // LIBBOOK_H
