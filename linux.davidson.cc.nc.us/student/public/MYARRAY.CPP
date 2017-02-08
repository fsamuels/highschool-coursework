#include "myarray.h"

myArray::myArray()
{ // Memory for 10 ARRAY_ELEMENT_TYPE objects


}

myArray::myArray(int initMax)
{ // post: Memory for 10 ints, pointed to by x, is allocated
  

}

myArray::myArray(const myArray & source)
{ // post: dynamically allocate memory for new objects during pass by value



}

myArray::~myArray()
{ // post: memory allocated for my_data is deallocated


}

void myArray::set(int subscript, ARRAY_ELEMENT_TYPE value)
{ // post: x[subscript] = value when subscript is in range
  //       If not, an error message is displayed.


}

// accessor
ARRAY_ELEMENT_TYPE myArray::sub(int subscript) const
{ // post: x[subscript] is returned when subscript is in range. 
  //       If not, an error message is displayed and x[0] is returned.
  

}

