//-----------------------------------------------------------------------
// file name: genbag.h
//
// Declares and implements a generic bag class
//-----------------------------------------------------------------------
#ifndef BAG_H
#define BAG_H
#include <iostream.h>

const int DEFAULT_INITIAL_BAG_CAPACITY = 32;

template <class BagElementType>
class bag {
public:
//--constructors
  bag();
  // post: Size of this bag is 0. 
  //       Initial capacity == DEFAULT_INITIAL_BAG_CAPACITY 

  bag(const bag< BagElementType > & source);
  // copy contructor

  ~bag();
  // destructor
  
//--modifiers
  void add(BagElementType newElement);
  // post: Add newElement to this bag and increase 
  //       the size of this bag object increased by +1.
  //       Note: If capacity < size, the bag doubles it capacity
  // First, increase the bag capacity if necessary
  
  bool remove(BagElementType removalCandidate);
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

  void first();
  // post: my_index points to the first item, 
  //       or if the bag is empty, isDone would now return true

  void next();
  // post: my_index points to the next item, or isDone now returns true
  
  bool isDone() const;
  // post: Returns true if the collection has been traversed 

  BagElementType currentItem() const;
  // post: Returns the item pointed to by the my_index

private:
  BagElementType * x; // x is a pointer to the first of many elements
  int my_size;
  int my_capacity;
  int my_index;                // internal cursor for iterating over all elements
};


// constructors/destructor

template <class BagElementType>
bag<BagElementType>::bag()
{ // post: Size of this bag is 0. 
  //       Initial capacity == DEFAULT_INITIAL_BAG_CAPACITY 
  my_size = 0;
  my_capacity = DEFAULT_INITIAL_BAG_CAPACITY;
  x = new BagElementType [my_capacity];
}

template<class BagElementType>
bag<BagElementType>::bag(const bag< BagElementType > & source)
{
  // Copy the data members
  my_size = source.my_size;
  my_index = source.my_index;
  my_capacity = source.my_capacity;
  
  // Allocate the memory for the new bag
  x = new BagElementType[my_capacity];
  
  // and finally, copy all values from source to destination
  for(int j = 0; j < my_capacity; j++)
  {  // deep copy means copy all elements, not just the address of the first
     x[j] = source.x[j];
  }
}


template <class BagElementType>
bag<BagElementType>::~bag()
{ // restore all allocated memory back to the free store
  delete [ ] x;
}

//--modifiers

template<class BagElementType>
void bag<BagElementType>::add(BagElementType newElement)
{
  // First check to see if we need to grow the bag
  if(my_size >= my_capacity)
  { // Capacity exceeded so double the capacity 
    my_capacity = 2 * my_capacity;

    // Allocate memory to store more objects
    BagElementType * extraData = new BagElementType[my_capacity];

    // Copy elements into the newly allocated memory
    for(int j = 0; j < my_size; j++)
    {
      extraData[j] = x[j];
    }

    // Deallocate old memory that is no longer needed
    delete [ ] x;

    // Let x point to the new larger memory
    x = extraData;
  }
  
  // Add newElement to the bag, at the last piece of available memory
  x[my_size] = newElement;
  // And make sure the size is always increased by +1
  my_size++;
}

template <class BagElementType>  
bool bag<BagElementType>::remove(BagElementType removalCandidate)
{ // post: If found, removalCandidate is removed from this bag.
  int subscript(0);

  // Sequentially search for removalCandidate
  while((subscript < my_size) && (x[subscript] != removalCandidate))
  {
    subscript++;
  }
  // assert: x[subscript] == removalCandidate if found, otherwise
  //         subscript == my_size to indicate removalCandidate was not found
   
  if(subscript == my_size)
  { // The removalCandidate was not found
   return false;
  }
  else
  { // First, move the last element to where removalCandidate was found
    x[subscript] = x[my_size-1];
    // and then decrease size by 1
    my_size--;
    // finally, report success to the client code where the message was sent
    return true;
  }
}

//--accessors

template <class BagElementType>
int bag<BagElementType>::capacity() const
{
  return my_capacity;   // the capacity of the bag
}

template <class BagElementType>
int bag<BagElementType>::size() const
{
  return my_size;
}

template <class BagElementType>
bool bag<BagElementType>::isEmpty() const
{
  return my_size == 0;
}

//--iterator functions

template <class BagElementType>
void bag<BagElementType>::first()
{
  my_index = 0;
}
  
template <class BagElementType>
void bag<BagElementType>::next()
{
  my_index++;
}    

template <class BagElementType>
bool bag<BagElementType>::isDone() const
{
  return my_index >= my_size;
}

template <class BagElementType>
BagElementType bag<BagElementType>::currentItem() const
{ 
  return x[my_index];
}

#endif  // #ifndef BAG_H
