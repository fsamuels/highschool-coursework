#include "cdstuff.h"

//////////////////////////////////////////////
////////////// track /////////////////////////
//////////////////////////////////////////////

track::track()
{
  my_title = "?title?";
  my_playTime = 0;
  my_cdNumber = 0;
  my_trackNumber = 0;
}

track::track(int initCdNumber, int initTrackNumber)
{
  my_cdNumber = initCdNumber;
  my_trackNumber = initTrackNumber;
}

track::track (string initTitle, seconds initPlayTime, 
             int initCdNumber, int initTrackNumber)
{
  my_title = initTitle;
  my_playTime = initPlayTime;
  my_trackNumber = initTrackNumber;
  my_cdNumber = initCdNumber;
}

seconds track::playTime() const
{
  return my_playTime;
}
  
int track::trackNumber() const
{
  return my_trackNumber;
}
  
int track::cdNumber() const
{
  return my_cdNumber;
}

string track::title() const
{
  return my_title;
}


//////////////////////////////////////////////
////////////// CD ////////////////////////////
//////////////////////////////////////////////
const int DEFAULT_NUMBER_OF_TRACKS = 10;

CD::CD()
{
  // Don't bother to do anything. 
  // Needed becausere
}

CD::CD(string initArtist, string initTitle)
{
  my_artist = initArtist;
  my_title = initTitle;
  my_size = 0; 
  my_index = -1;  // CD::first must be called
  my_data.resize( DEFAULT_NUMBER_OF_TRACKS );
}

void CD::addTrack(const track & nextTrack)
{ // This function tries to balance time space tradeoffs
  // You could change DEFAULT_NUMBER_OF_TRACKS or resize by 2 
  // resize is an expensive operation. 

  // first see if we need to grow the vetor by 1
  if(my_size + 1 >= my_data.capacity() )
    my_data.resize( my_data.capacity() + 1 );
  my_data[my_size] = nextTrack;
  my_size++;
}

string CD::artist() const
{
  return my_artist;
}

string CD::title() const
{
  return my_title;
}

void CD::first() 
{
  my_index = 0;
}

void CD::next()
{
  my_index++;
}

bool CD::isDone() const
{
  return (my_index >= my_size);
}

track CD::currentItem() const
{
  return my_data[my_index];
}


//////////////////////////////////////////////
////////////// cdCollection //////////////////
//////////////////////////////////////////////
const int DEFAULT_NUMBER_OF_CDS

cdCollection::cdCollection()
{
  my_size = 0;
  my_index = -1;
  my_data.resize(DEFAULT_NUMBER_OF_CDS);
}

cdCollection::initializeCdCollection(string fileName)
{
  int CdNumberInPhysicalJukeBox;
  string artistLabel, titleLabel;      // will be thrown away
  int trackNumber, minutes, secnds;    // seconds is typedefed as long
  string songTitle, CdArtist, CdTitle;
  
  ifstream inFile(fileName.c_str());
  // Terminate right away if the file is not found
  assert( inFile );

  while(inFile >> artistLabel)
  {
    if(artistLabel != "#ARTIST")
    {
      cout << "\n**ERRROR** File Corrupted" << endl;
      cout << "terminating program");
    }
    getline(inFile, CdArtist);

    inFile >> CdNumberInPhysicalJukeBox;  // these must match CD player
  
  inFile >> titleLabel;

  getline(inFile, CdTitle);

  CD aCD;
  while(inFile.peek() != '#')
  {
    inFile >> trackNumber  >> minutes >> secnds;
    getline(inFile, songTitle);
    aCD.addTrack( track( songTitle, minutes*60+secnds, trackNumber, minutes ) );
  }
  addCD(aCD);
}
  

bool cdCollection::addCD(const CD & nextCD)
{
 // first see if we need to grow the vetor by 1
  if(my_size + 1 >= my_data.capacity() )
    my_data.resize( my_data.capacity() + 1 );
  my_data[my_size] = nextCD;
  my_size++;

}

bool cdCollection::removeCD(const CD & aCD)
{
  // under construction
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

track cdCollection::currentItem() const
{
  return my_data[my_index];
}

