//////////////////////////////////////////////
////////////// track /////////////////////////
//////////////////////////////////////////////
#include "track.h"

track::track()
{
  my_title = "?title?";
  my_playTime = 0;
  my_cdNumber = 0;
  my_trackNumber = 0;
}

track::track(const track & source)
{
  my_title = source.my_title;
  my_playTime = source.my_playTime;
  my_cdNumber = source.my_cdNumber;
  my_trackNumber = source.my_trackNumber;
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
