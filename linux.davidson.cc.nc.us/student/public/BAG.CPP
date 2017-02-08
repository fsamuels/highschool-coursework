#include "bag.h"

bag::bag()
{
  my_size = 0;
  my_capacity = DEFAULT_INITIAL_BAG_CAPACITY;
  my_element.resize(my_capacity);
}

bag::bag(int initCapacity)
{ // pre: initCapacity >= 1;
  my_size = 0;
  my_capacity = initCapacity;
  my_element.resize(my_capacity);
}

void bag::add(BAG_ELEMENT_TYPE newElement)
{
  // First, increase the bag capacity if necessary
  if(my_size >= my_element.capacity())
  {
    my_capacity = 2 * my_element.capacity();
    my_element.resize( my_capacity );
  }

  // Store the argument into the vector of BAG_ELEMENT_TYPE objects...
  my_element[my_size] = newElement;
  // ...and make sure my_size is always increased by +1:
  my_size++;
}

bool bag::remove(BAG_ELEMENT_TYPE removalCandidate)
{
  int subscript(0);

  // Sequentially search for removalCandidate
  while((subscript < my_size) && (my_element[subscript] != removalCandidate))
  {
    subscript++;
  }
  // assert: my_element[subscript] == removalCandidate if found, otherwise
  //         subscript == my_size to indicate removalCandidate was not found
   
  if(subscript == my_size)
  { // The removalCandidate was not found
	  return false;
  }
  else
  { // First, move the last element to where removalCandidate was found
    my_element[subscript] = my_element[my_size-1];
    // and then decrease size by 1
    my_size--;
    // finally, report success to the client code where the message was sent
    return true;
  }
}

int bag::capacity() const
{
  return my_element.capacity();   // the capacity of the vector
}

int bag::size() const
{
  return my_size;
}

bool bag::isEmpty() const
{
  return my_size == 0;
}

// The Iterator Functions

void bag::first() const
{ // Make sure there is at least one item in the bag
  if(my_size >= 0)
  { // Cast away const so this appears to not modify the object
    // This is the only situation this trick should be used to subvert the meaning of const
    ((bag*)this)->my_index = 0;
  }
}
  
void bag::next() const
{
  // Cast away const so this appears to not modify the object
  // This is the only situation this trick should be used to subvert the meaning of const
  ((bag*)this)->my_index++;
}    

bool bag::isDone() const
{
  return my_index >= my_size;
}

BAG_ELEMENT_TYPE bag::currentItem() const
{ 
  return my_element[my_index];
}
