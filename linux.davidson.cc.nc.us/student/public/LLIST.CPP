// file name: llist.cpp
// Implement a traversable linked list with append and remove operations
#include "llist.h" // for separate compilation

////////////////////////////////////////
// Implement node's constructers first//
////////////////////////////////////////
node::node()
{
  structs_next = NULL;
}

node::node(listElementType data)
{
  my_data = data;
  structs_next = NULL;
}

///////////////////////////////
// Implement LinkedList next //
///////////////////////////////
LinkedList::LinkedList()
{
  // Create a dummy header node to make things easier
  my_first = new node; // call default constructor
  my_last = my_first;
  my_index = NULL;
  my_size = 0;
}

//--modifiers

void LinkedList::append(const listElementType& newElement)
{
  // Allocate and initialize a new node 
  my_last->structs_next = new node(newElement);
  
  // Update the last pointer
  my_last = my_last->structs_next;

  // Maintain current size
  my_size++;
}

bool LinkedList::remove(const listElementType& removalElement)
{ // pre: The listElementType defines ==
  
  // have current point to the first (there is a dummy head node)
  node* current = my_first->structs_next;
  node* prev = my_first;

  // Check the remaining list elements until found or no more
  while(current != NULL)
  {
    if(current->my_data == removalElement)
    {
      break;
    }
    else
    {
      prev = current;
      current = current->structs_next;
    }
  }
  
  // Don't delete a nonexistant node
  if(current == NULL)
  { // removalElement was not found
    return false;
  }
  else
  { // Take out the element
    prev->structs_next = current->structs_next;
    delete current;
    // Maintain current size
    my_size--;
    return true;
  }
}

//--accessor
int LinkedList::size() const
{
  return my_size;
}

//--iterator functions

void LinkedList::first() const
{ // Make sure there is at least one item in the LinkedList
  if(my_size >= 0)
  { // Cast away const so this appears to not modify the object.
    // This is the only situation this trick should be used to 
    // subvert the meaning of const.
    ((LinkedList*)this)->my_index = my_first->structs_next; // dummy first
  }
}
  
void LinkedList::next() const
{
  // Cast away const so this appears to not modify the object.
  // This is the only situation this trick should be used to
  // subvert the meaning of const.
  ((LinkedList*)this)->my_index = ((LinkedList*)this)->my_index->structs_next;
}    

bool LinkedList::isDone() const
{
  return my_index == NULL;
}

listElementType& LinkedList::currentItem() 
{ 
  return my_index->my_data;
}

const listElementType& LinkedList::currentItem() const
{ 
  return my_index->my_data;
}



