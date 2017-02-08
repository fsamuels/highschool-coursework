#ifndef MYARRAY_H
#define MYARRAY_H

class myArray {
public:
//--constructors
  myArray();
  // Memory for 10 ARRAY_ELEMENT_TYPE objects

  myArray(int initMax);
  // post: Memory for 10 ints, pointed to by x, is allocated

  myArray(const myArray & source);
  // post: dynamically allocate memory during pass by value

//--destructor
   ~myArray();
  // post: memory allocated for my_data is deallocated

//--modifier
  void set(int subscript, ARRAY_ELEMENT_TYPE value);
  // post: x[subscript] = value when subscript is in range
  //       If not, an error message is displayed.

// accessor
  ARRAY_ELEMENT_TYPE sub(int subscript) const;
  // post: x[subscript] is returned when subscript is in range. 
  //       If not, display an error message and return [0].

private:
  ARRAY_ELEMENT_TYPE * my_data;
  int my_capacity;
};

#endif
