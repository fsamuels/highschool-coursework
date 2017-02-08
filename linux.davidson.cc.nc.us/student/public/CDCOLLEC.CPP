#include <assert.h>    // for the assert function
#include <fstream.h>    // for class ifstream
#include "string"     // for a string class
#include "cdcollec.h" // allows for separate compilation to an object file
#include "cddefs.h"   // for  DEFAULT_NUMBER_OF_TRACKS and DEFAULT_NUMBER_OF_CDS

cdCollection::cdCollection()
{
  char temp[128];   // used to get a line of string data
  my_size = 0;
  my_index = -1;
  string fileName(CD_FILE_NAME) ;
  ifstream inFile(fileName.c_str());
  // Terminate right away if the file is not found
  if(! inFile )
  {
    cout << "**Error initializing CD collection from cdCollection::cdCollection()" << endl;
    cout << "**Could not open '" << fileName << "'. Teminating program" << endl;
    exit(0);
  }

  int CdNumberInPhysicalJukeBox;
  string artistLabel, titleLabel;      // will be thrown away
  int trackNumber, minutes, seconds;
  string songTitle, artist, title;


  my_data.resize(DEFAULT_NUMBER_OF_CDS);

  while( (inFile >> artistLabel)  &&  (artistLabel != "#END") )
  {
    if(artistLabel != "#ARTIST")
    {
      cout << "\n**ERRROR** CD data file is messed up. ";
      cout << "All it takes is one chaacter out of place." << endl;
      cout << "Terminating program -- format input file very carefully";
    }

    inFile.getline(temp, 128, '\n');
    artist = temp;
    artist = artist.substr(1, artist.length()-2 );

    inFile >> CdNumberInPhysicalJukeBox;  // these must match physical CD player

    inFile.getline(temp, 128, '\n');
    title = temp;
    title = title.substr(1, title.length()-2 );




    CD aCD(artist, title, CdNumberInPhysicalJukeBox);

    while(inFile.peek() != '#')
    {
      inFile >> trackNumber  >> minutes >> seconds;
      inFile.getline(temp, 128, '\n');
      songTitle = temp;
      songTitle = songTitle.substr( 1, songTitle.length()-2 );
      aCD.addTrack( track( songTitle, minutes*60+seconds, CdNumberInPhysicalJukeBox, trackNumber ) );
    }
    addCD(aCD);
  }
}

cdCollection::cdCollection(const cdCollection & source)
{
  cout << "In copy construcr" << endl;
}

void cdCollection::addCD(const CD & nextCD)
{
 // first see if we need to grow the vector by 2
  if(my_size + 1 >= my_data.capacity() )
    my_data.resize( my_data.capacity() + 2 );
  my_data[my_size] = nextCD;
  my_size++;
}

bool cdCollection::removeCD(const CD & aCD)
{
  cout << "\nbool cdCollection::removeCD(const CD & aCD)  is under construction" << endl;
  return false;
}

void cdCollection::first() 
{
  my_index = 0;
}

void cdCollection::next()
{
  my_index++;
}

bool cdCollection::isDone() const
{
  return (my_index >= my_size);
}

CD cdCollection::currentItem() const
{
  return my_data[my_index];
}

int cdCollection::size() const
{
   return my_size;
}

CD cdCollection::getCD(int cdNumber) const
{
  return my_data[cdNumber-1];
}
