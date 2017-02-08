//----------------------------------------------------------------------
// file name lendable.h
//----------------------------------------------------------------------
#ifndef LENDABLE_H
#define LENDABLE_H
#include "string" // for class string
#include "date"   // class Date is from Owen Astrachan's book:
                  // "A Computer Science Tapestry", // McGraw Hill, 1997
class lendable {
public:
//--constructors
  lendable(string initID);

//--accessors
  bool isOverdue() const;
  bool isAvailable() const;
  string lendableID() const;
  string borrowersID() const;
  double lateFee() const;
  Date dueDate() const; // needed by derived classes during computeLateFee

//--modifiers
  void checkSelfIn();   
  void checkSelfOut(string borrowersID);

//--pure virtual function to be implemented by the derived classes
protected:
  virtual Date computeDueDate() const = 0;   
  virtual double computeLateFee() const = 0; 
    
private:
  string my_ID;
  Date my_dueDate;
  bool my_availability;
  string my_borrowersID;
};


class book : public lendable {
public:
//--constructor
  book(string initID, string initAuthor, string initTitle);

//--virtual functions that must be implemented
  Date computeDueDate() const;   
  double computeLateFee() const; 

//--additional accessors
  string author();
  string title();
    
private:
  string my_author;
  string my_title;
};

class video : public lendable {
public:
//--constructor
  video(string initID, string initTitle);

//--virtual functions that must be implemented
  Date computeDueDate() const;   
  double computeLateFee() const; 

//--additional accessors
  string title();
    
private:
  string my_title;
};

#endif