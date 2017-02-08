#ifndef TRACKSELECTOR_H
#define TRACKSELECTOR_H
#include "cdcollec"
#include "cd"

class trackSelector {    
public:
  void message(string theMessage);
  track getTrack(cdCollection & theCDCollection);
private:  
  // no data members when cout and cin are used
};

#endif
