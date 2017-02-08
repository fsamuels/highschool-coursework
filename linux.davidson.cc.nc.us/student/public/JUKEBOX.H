#ifndef JUKEBOX_H
#define JUKEBOX_H
#include "cdcollec"
#include "cdplayer"
#include "cardread"
#include "tracksel"

class jukeBox {   
public:
  jukeBox();
  // initialize the cdPlayer and possibly do some other things

  void processOneUser();
  // Do whatever is necessary to process one user request

  bool isRunning();
  // true until jukeBox somehow detects that it is time to shut down

private:
//--data members
  studentIdType my_currentStudent;
  track my_currentSelection;

  cardReader my_cardReader;
  cdCollection my_cdCollection;
//  studentCollection my_studentCollection;
  cdPlayer my_cdPlayer;
  trackSelector my_trackSelector;
};

#endif