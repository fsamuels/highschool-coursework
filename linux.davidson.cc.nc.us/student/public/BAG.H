//-----------------------------------------------------------------------
// file name: bag.h
//
// Defines and implements class bag
//-----------------------------------------------------------------------
#ifndef BAG_H
#define BAG_H
#include <iostream.h>
#include "vector"
#include "bool"

const int DEFAULT_INITIAL_BAG_CAPACITY = 16;

class bag {
public:
//--constructors
  bag();
  // post: Size of this bag is 0. 
  //       Initial capacity == DEFAULT_INITIAL_BAG_CAPACITY 

  bag(int initCapacity);
  // pre:  initCapacity >= 1
  // post: size of this bag is bag to 0 with the capacity 
  //       to store initCapacity BAG_ELEMENT_TYPE objects 

//--modifiers
  void add(BAG_ELEMENT_TYPE newElement);
  // post: Add newElement to this bag and increase 
  //       the size of this bag object increased by +1.

 //       Note: If capacity < size, the bag doubles it capacity

  bool remove(BAG_ELEMENT_TYPE removalCandidate);
  // post: If found, removalCandidate is removed from this bag.
  
//--accessors

  int capacity() const;
  // post: return the maximum number of elements that could be stored in this bag

  int size() const;
  // post: return the number of elements that are currently in this bag
  //       the number of objects added but not removed.

  bool isEmpty () const;
  // post: Returns true if there are zero items in the bag.
  //       Returns false if there is one more added elements

//--iterator functions

  void first() const;
  // post: my_index points to the first item, 
  //       or if the bag is empty, isDone would now return true

  void next() const;
  // post: my_index points to the next item, or isDone now returns true
  
  bool isDone() const;
  // post: Returns true if the collection has been traversed 

  BAG_ELEMENT_TYPE currentItem() const;
  // pre:  ! isDone && my_size > 0
  // post: Returns the item pointed to by the my_index

private:
  int my_size;
  int my_capacity;
  int my_index;   // an internal cursor for iterating over all elements
  vector <BAG_ELEMENT_TYPE> my_element;
};

#endif  // #ifndef BAG_H
