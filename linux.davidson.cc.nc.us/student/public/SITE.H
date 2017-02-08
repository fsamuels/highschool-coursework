//--------------------------------------------------------------------
// file name: site.h
//--------------------------------------------------------------------
#ifndef SITE_H
#define SITE_H

#include <string>   
using namespace std;
#include "matrix"    // for class table array2

class site {
public:
  void reportHOV(string fileName);

private:
  matrix <double> my_humanData; // This gives us a large enough array2 object
};

#endif  // SITE_H


