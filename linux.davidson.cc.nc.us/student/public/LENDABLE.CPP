// test date and lendable
#include "lendable.h" 

const int BOOK_BORROW_DAYS = 14;
const int VIDEO_BORROW_DAYS = 2;
const int CDROM_BORROW_DAYS = 7;
const double BOOK_LATE_FEE = 0.50;
const double VIDEO_FLAT_LATE_FEE = 5.00;
const double VIDEO_LATE_FEE = 1.50;
const double CDROM_LATE_FEE = 2.50;

//////////////////////////////////////////
// Implement common lendable operations //
//////////////////////////////////////////

// Use these two special values to indicate dueDate and borrowersID are irrelevant
const Date emptyDate = Date(9,9,9999);  
const string emptyID = "?";

lendable::lendable(string initID) 
{
  my_ID = initID; 
  my_dueDate = emptyDate; 
  my_availability = true; 
  my_borrowersID = emptyID;
}

bool lendable::isOverdue() const
{
  Date today;  
  // assert: today contains today's date as stored in the computer clock
  return my_dueDate.Absolute() <= today.Absolute();
}

bool lendable::isAvailable() const
{
  return my_availability;
}

string lendable::lendableID() const
{
  return my_ID;
}

string lendable::borrowersID() const
{
  return my_borrowersID;
}

Date lendable::dueDate() const
{
  return my_dueDate;
}

double lendable::lateFee() const
{
  return computeLateFee();
}
 
void lendable::checkSelfOut(string borrowersID)
{
  my_dueDate = computeDueDate();  
  // polymorphism in action. A runtime, the system
  // knows which computeDueDate implementation to use.
  my_availability = false;
  my_borrowersID = borrowersID;
}

void lendable::checkSelfIn()
{
  my_availability = true;
  my_borrowersID = emptyID;
  my_dueDate = emptyDate;
}

//////////////////////////////////////////
/////////// Implement book ///////////////
//////////////////////////////////////////

book::book(string initID, string initAuthor, string initTitle)
     : lendable (initID) 
{
   my_author = initAuthor; 
   my_title = initTitle;
  // Initialization list took care of everything
}

Date book::computeDueDate() const
{
  Date today;
#ifdef DebuggingLateFee
  return today - BOOK_BORROW_DAYS;
#else 
  return today + BOOK_BORROW_DAYS;
#endif
}

double book::computeLateFee() const
{
  Date today;
  int daysLate;
  daysLate = today - dueDate(); // call protected base class member function
  // daysLate will be negative unless the video is overdue 
  if(daysLate > 0)
    return daysLate * BOOK_LATE_FEE;
  else
    return 0.00;
}

string book::author()
{
 return my_author;
}

string book::title()
{
  return my_title;
}
  
//////////////////////////////////////////
/////////// Implement video //////////////
//////////////////////////////////////////

video::video(string initID, string initTitle)
      : lendable(initID), 
        my_title(initTitle)
{
  // Initialization list took care of everything
}

Date video::computeDueDate() const
{
  Date today;
#ifdef DebuggingLateFee
  return today - VIDEO_BORROW_DAYS;
#else
  return today + VIDEO_BORROW_DAYS;
#endif
}

double video::computeLateFee() const
{
  Date today;
  int daysLate;
  daysLate = today - dueDate(); // call protected base class member function
  // daysLate will be negative unless the video is overdue 
  if(daysLate > 0)
    return VIDEO_FLAT_LATE_FEE + daysLate * VIDEO_LATE_FEE;
  else
    return 0.00;
}

string video::title()
{
  return my_title;
}
  