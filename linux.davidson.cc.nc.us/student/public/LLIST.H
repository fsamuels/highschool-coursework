#ifndef LLIST_H
#define LLIST_H

struct node {
public:
// constructors
   node();
   node(listElementType data);

// public data
   listElementType my_data;
   node* structs_next;
};

class LinkedList {
public:
//--constructor
  LinkedList();
  // Construct an empty list

//--modifiers
  void append(const listElementType& newElement);
  // List == List with newElement added at the end

  bool remove(const listElementType& removalElement);
  // pre:  The listElementType defines ==
  // post: List == List with removalElement removed if found

//--accessor
  int size() const;
  // Return the number of elements currently stored in the list

//--iterator functions
  void first() const;
  // post: my_index points to the first item, 
  //       or if the LinkedList is empty, isDone would now return true

  void next() const;
  // post: my_index points to the next item, or isDone now returns true
  
  bool isDone() const;
  // post: Returns true if the collection has been traversed 

  listElementType& currentItem();
  // pre:  ! isDone && my_size > 0
  // post: Returns address of the item pointed to by the my_index

  const listElementType& currentItem() const; 
  // pre:  ! isDone && my_size > 0
  //       Allows lists to be passed by const reference
  
private:
  // An inner class referenced frequently by LinkedList operations

  node* my_first;
  node* my_last;
  node* my_index;
  int my_size;
};

#endif