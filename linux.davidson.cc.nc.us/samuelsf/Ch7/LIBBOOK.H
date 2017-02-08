//--------------------------------------------------------
// file name: libbook.h
//
// defines: class libraryBook
//--------------------------------------------------------
#ifndef LIBBOOK_H
#define LIBBOOK_H
#include "string"
//#include "bool" //why it was there, i don't know

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

///////////////////additions by forrest////////////////
	bool isAvailable() const;
	// returns true if book is mot borrowed and false if it is
//////////////////end of additions/////////////////////


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
   bool my_availability;
};

#endif   // LIBBOOK_H
