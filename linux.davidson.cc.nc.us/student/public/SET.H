//-----------------------------------------------------------------------
// SPECIFICATION FILE set.h
//
// Declares: class set
//-----------------------------------------------------------------------
#ifndef SET_H
#define SET_H
#include "vector"  // for class vector

class set {
public:
  set();
  // post: size of this set == 0. The capacity is a default size (16)

  set(int initCapacity);
  // pre:  initCapacity >= 1
  // post: size of this set == 0 with the capacity to store
  //       initCapcity SET_ELEMENT_TYPE objects

//--modifiers
  bool add(SET_ELEMENT_TYPE newElement);
  // post: If newElement is not in this set, newElement is added
  //       and the size of the set increased by +1.

  bool remove(SET_ELEMENT_TYPE removalCandidate);
  // post: If removalCandidate is found, the element is removed from set.
  // Note: The vector of elements and the number of elements
  //       added (size) are accessible from this member function.

  int capacity() const;
  // post: return the maximum number of elements that could be stored in this set

  int size() const;
  // post: return the number of elements that are currently in this set
  //       the number of objects added but not removed.

//--iterator functions
  void first();
  // post: my_index points to the first item, 
  //       or if the bag is empty, isDone would now return true

  void next();
  // post: my_index points to the next item, or isDone now returns true
  
  bool isDone() const;
  // post: Returns true if the collection has been traversed 

  SET_ELEMENT_TYPE currentItem() const;
  // pre:  ! isDone && my_size > 0
  // post: Returns the item pointed to by the my_index

private:
  int my_size;
  int my_capacity;
  int my_index;   // an internal cursor for iterating over all elements
  vector <SET_ELEMENT_TYPE> my_data;
};

#endif  // #ifndef SET_H
