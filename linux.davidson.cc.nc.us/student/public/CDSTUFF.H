//-------------------------------------------------------------
// File name: cdstuff.h
// This file defines early versions of the following classes
//    class track               // early draft
//    class CD                  // early draft
//    class cdCollection        // early draft
//-------------------------------------------------------------
#ifndef CDSTUFF_H
#define CDSTUFF_H
#include <vector>
#include <string>
using namespace std;

typedef long seconds;

//////////////////////////////////////////////
////////////// track /////////////////////////
//////////////////////////////////////////////
class track {   
public:
  track();
  // default constructor 

  track(int initCdNumber, int initTrackNumber);
  // allows easier testing as in theCdPlayer.playTrack( track(3, 4) );

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
  
//////////////////////////////////////////////
////////////// CD ////////////////////////////
//////////////////////////////////////////////
class CD {
public:
  CD();
  // default constructor allows vector of tracks

  CD(string initArtist, string initTitle);
  // initialize a CD with 0 tracks

  void addTrack(const track & nextTrack);
  // add a new track--missed this during desin

  string artist() const;

  string title() const;

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
};

//////////////////////////////////////////////
////////////// cdCollection //////////////////
//////////////////////////////////////////////
class cdCollection {      
public:
  cdCollection();

  initializeCdCollection(string fileName);
  // Reads all the data from a file to initialize CD collection

  bool addCD(const CD & nextCD);
  // add a CD to the collection if possible. Return false if it can't

  bool removeCD(const CD & aCD);
  // remove CD if possible. Return false if it doesn't exist

//--iterator functions:
  void first();    // let index point to the first item

  void next();     // let index point to the next item (false at end)

  bool isDone() const;   // return true when traversal is done

  CD currentItem() const;  // returns the item referred to by next

private:
  vector <CD> my_data;    // store the CDs
  int my_size;            // the number of CDs in the collection
  int my_index;           // the subscript of the current item
};

#endif  // #ifndef CDSTUFF_H

