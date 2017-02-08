#include "cd"
#include "compfun" // for causeApause();

void show( const track & t2)
{
  cout.width(2);
  cout << t2.trackNumber();
  cout.width(3);
  cout << t2.cdNumber() << "  ";
  cout << t2.title() << " " << (t2.playTime() / 60)
                     << ":" << (t2.playTime() % 60) << endl;
}

int main()
{ // test drive CD

  CD aCD("Browne, Jackson", "Facing East", 2);

  aCD.addTrack( track("Looking East",         4*60+56, 5, 1 ) );

  aCD.addTrack( track("Barricades of Heaven", 5*60+42, 5, 2 ) );
  aCD.addTrack( track("Some Bridges",         4*60+51, 5, 3 ) );
  aCD.addTrack( track("Information Wars",     5*60+14, 5, 4 ) );
  aCD.addTrack( track("I'm the Cat",          3*60+55, 5, 5 ) );
  aCD.addTrack( track("Culver Moon",          5*60+45, 5, 6 ) );
  aCD.addTrack( track("Baby How Long",        5*60+05, 5, 7 ) );
  aCD.addTrack( track("Nino",                 5*60+14, 5, 8 ) );

  aCD.addTrack( track("Alive in the World",   4*60+51, 5, 9 ) );
  aCD.addTrack( track("It is One",            4*60+57, 5, 10) );

  // add a couple more than the default CD capacity size of 10

  aCD.addTrack( track("Fake Eleventh", 0, 5, 11) );
  aCD.addTrack( track("Fake Twelfth",  0, 5, 12) );
 
  cout << aCD.artist() << "   " << aCD.title() << endl;

  // Iterate over all tracks on the CD
  track aTrack;

  aCD.first();
  while( ! aCD.isDone() )
  {
    aTrack = aCD.currentItem();
    show(aTrack);

    aCD.next();
  }

  causeApause();


  return 0;
}
