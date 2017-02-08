#ifndef TRACK_H
#define TRACK_H
#include "string"

typedef long seconds;

class track {   
public:
  track();
  // default constructor 

  track(const track & source);
  // copy constructor

  track (string initTitle, seconds initPlayTime, 
         int initCdNumber, int initTrackNumber);
  // initializes the private data of a track

  string title() const;
  // return the tracks title
  
  seconds playTime() const;
  // returns the number of seconds required to play this track

  int cdNumber() const;
  // the tray location of the CD in the physical CD player

  int trackNumber() const;
  // this track's location on the CD

private:
  string my_title;
  seconds my_playTime;
  int my_cdNumber;
  int my_trackNumber;
};

#endif
