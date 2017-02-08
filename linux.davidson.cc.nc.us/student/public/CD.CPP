#include "cd.h"     // allow for separate compilation to an object file
#include "track"    // for class track
#include "cddefs.h" // for DEFAULT_NUMBER_OF_TRACKS 

//////////////////////////////////////////////
////////////// CD ////////////////////////////
//////////////////////////////////////////////

CD::CD()
{
  // Don't bother to do anything. 
  // Needed to have vector < CD > aVectorOfCds.
}

CD::CD(const CD & source)
{
  my_artist = source.my_artist;
  my_title = source.my_title;
  my_size = source.my_size; 
  my_index = source.my_index;  
  my_cdNumber = source.my_cdNumber;  
  my_data = source.my_data;
}

CD::CD(string initArtist, string initTitle, int initCdNumber)
{
  my_artist = initArtist;
  my_title = initTitle;
 
 my_cdNumber = initCdNumber;
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
    my_data.resize( my_data.capacity() + 3 );
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

int CD::cdNumber() const
{
  return my_cdNumber;
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


track CD::getTrack(int trackNum) const
{
  return my_data[trackNum-1];
}

int CD::size() const
{
  return my_size;
}

