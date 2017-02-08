//-------------------------------------------------------------
// File name: cd.h
// This file defines an early version of class CD
//-------------------------------------------------------------
#ifndef CD_H
#define CD_H

//////////////////////////////////////////////
////////////// CD ////////////////////////////
//////////////////////////////////////////////
#include "vector" // for class vector
#include "string" // for class string
#include "track"  // for class track


class CD {
public:
  CD();
  // default constructor allows vector of tracks

  CD(const CD & source);
  // copy  constructor

  CD(string initArtist, string initTitle, int initCdNumber);
  // initialize a CD with 0 tracks

  void addTrack(const track & nextTrack);
  // add a new track--missed this during design

  string artist() const;
  // return this CD's artist

  string title() const;
  // return the title of this CD

  int cdNumber() const;
  // return the physical location of this CD in the CD player (the tray number)

  track getTrack(int trackNum) const;

  int size() const;
  // return the number of tracks on this CD

//--iterator functions
  void first();    
  void next();     
  bool isDone() const;   
  track currentItem() const;  

private:
  string my_artist;
  string my_title;
  vector < track > my_data; 
  int my_size;            
  int my_index; 
  int my_cdNumber;
};

#endif
