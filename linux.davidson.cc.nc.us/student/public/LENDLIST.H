// file lendlist.h
#ifndef LENDLIST_H
#define LENDLIST_H
#include "lendable"
#include <vector>
using namespace std;

// Named constants required in endlist.cpp. 
const string bookFileName = "book.dat";
const string videoFileName = "video.dat";
const string cdRomFileName = "cdrom.dat";
const int sizeIncrement = 1000; // resize vector to capacity + sizeIncrement 

class lendableList {
public:
  lendableList();
  bool putLendable(const lendable & aLendable);
  // Replace the existing lendable. If non-existent, return false

  void addLendable(lendable* aLendable);
  // Add the lendable to the lendable list.

// accessors
  bool getLendable(string searchID, lendable* & aLendable) const;
  // If lendablID is found, return true and set the second argument to the lendable

private:
  vector<lendable *> my_data;
  int my_size;
  int my_index;
};

#endif