#include <iostream.h>
#include "vector" // For the vector<CLASS> class

typedef int vectorElementType;

void init(vector <vectorElementType> & x, int & n); // Neef prototypes to avoid Codewarrior warnings
void display(const vector <vectorElementType> & x, int & n); 
void swap(vectorElementType & a, vectorElementType & b);
void sort(vector < vectorElementType > & data, int n); 

void init(vector <vectorElementType> & x, int & n)
{ // post: x becomes a new vector precisely the size needed
  n = 5;
  x.resize(n);
  x[0] = 76;
  x[1] = 74;
  x[2] = 100;
  x[3] = 62;
  x[4] = 89;
}


void display(const vector <vectorElementType> & x, int & n)
{ // post: Show all elements
  int j;

  cout << "The vector: " << endl;
  for(j = 0; j < n; j++)
  {
    cout.width(2);
    cout << j << ". ";
    cout.width(5);
    cout << x[j] << endl;
  }
}

void swap(vectorElementType & a, vectorElementType & b)
{ // post: Exchange values of a and b
  vectorElementType temp;
  
  temp = a; // Hold on to a's value so a can ge changed
  a = b;
  b = temp;
}


void sort(vector < vectorElementType > & data, int n)
{ // post: Data elements are in descending order
  int j, top, subscriptOfLargest;
  subscriptOfLargest = 0;
  for(top = 0; top < n - 1; top++)
  {
    subscriptOfLargest = top;
    for(j = top + 1; j < n; j++)
    {
      if(data[j] > data[subscriptOfLargest])
      subscriptOfLargest = j;
    }
  swap(data[subscriptOfLargest], data[top]);
  }
}

int main()
{
  vector<int> test; // Default vector capacity is 0
  
  int n;
  init(test, n);
  sort(test, n);
  display(test, n);

  return 0;
}
