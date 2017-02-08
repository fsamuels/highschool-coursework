//-------------------------------------------------------------
// File name: cdcollec.h
// This file defines an early version of class cdCollection
//-------------------------------------------------------------
#ifndef CDCOLLEC_H
#define CDCOLLEC_H
#include "vector"  // for class vector
#include "string"  // for class string
#include "cd"      // for class cd

//////////////////////////////////////////////
////////////// cdCollection //////////////////
//////////////////////////////////////////////
class cdCollection {      
public:
  cdCollection();
  // pre:  The file withthe CD data is in the right place.
  // post: The cdCollection represents all CDs in the physical CD player.

  cdCollection(const cdCollection & source);
  
  void addCD(const CD & nextCD);
  // post: Add a CD to the collection if possible. 

  bool removeCD(const CD & aCD);
  // post: Remove CD if possible. Return false if it doesn't exist

  int size() const;
  // post: return the number of CDs in the collection

  CD getCD(int cdNumber) const;
  // pre:  cdNumber >= 1 and cdNumber <= cdCollection::size()
  // post: Returns an entire CD based on the CD# argument

//--iterator functions:
  void first();    // let index point to the first item
  void next();     // let index point to the next item (false at end)
  bool isDone() const;   // return true when traversal is done
  CD currentItem() const;  // returns the item referred to by next

private:
  vector < CD > my_data;  // store the CDs
  int my_size;            // the number of CDs in the collection
  int my_index;           // the subscript of the current item
};

#endif  // #ifndef CDCOLLEC_H
