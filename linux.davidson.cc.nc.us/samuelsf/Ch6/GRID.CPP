// File: grid.cpp
// From: Computing Fundamentals with C++, Second Edition
//       Rick Mercer, Franklin, Beedle, and Associates
// DRAFT += DRAFT += DRAFT += DRAFT += DRAFT += DRAFT +=
#include <iostream> // for endl and the objects cout, cin
#include <cassert>   // for function assert
#include <cstdlib>   // for function exit, rand() and srand()
#include <ctime>     // for TIME
#include <string>     // for class string
using namespace std;
#include "/student/csc134HA/samuelsf/Ch6/grid.h"


///////////////////////////////////////////////////////////////////////////
///// IMPLEMENT THE MEMBER FUNCTIONS //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

// The constant definitions  (use = instead of () so it works with Borland
const char intersectionChar = '.';
const char beenThereChar = ' ';
const char blockChar = '#';
const char thingHereChar = 'O';
const char moverOnThingChar = '&';
const int north = 0;
const int east = 1;
const int south = 2;
const int west  = 3;

// -- constuctors

grid::grid()
{ // Default constructor
}


grid::grid(int totalRows, int totalCols)
{ // Set up a border on the edges with one escape route
  int r, c;

  assert(totalRows <= maxRows);
  assert(totalRows >= 0);
  assert(totalCols <= maxCols);
  assert(totalCols > 0);

  showPath = 1;   // Show path when 1, when it's 0 keep the intersection visible
  lastRow = totalRows-1;
  lastCol = totalCols-1;

  for(r = 0; r <= lastRow; r++)
	 for(c = 0; c <= lastCol; c++)
		rectangle[r][c] = intersectionChar;

  for (c = 0; c <= lastCol; c++)
  {
	 rectangle[0][c] = blockChar;         // block first row
	 rectangle[lastRow][c] = blockChar;   // blocked last row
  }

  for (r = 0; r <= lastRow; r++)
  {
	 rectangle[r][0] = blockChar ;        // block first column
	 rectangle[r][lastCol] = blockChar ;  // block last column
  }

  // Put the mover somewhere in the grid, but NOT a border
  srand( (unsigned)time( NULL ) );        // use the clock to randomize
  currentRow = rand() % (lastRow-1) + 1;
  currentCol = rand() % (lastCol-1) + 1;

  // Pick a random direction
  int direct(rand() % 4);
  facing = direct;
  setIcon();
  rectangle[currentRow][currentCol] = icon;

  // Put one opening on any of the four edges
  if(rand() % 2 == 0)
  { // set on top or bottom at any column
    c = rand() % lastCol;
	
	if(c == 0)
      c++;           // avoid upper and lower left corner exits (see below)
	if(c == lastCol)
	  c--;           // avoid upper and lower right corner exits (see below)
    
	if(rand() % 2 == 0 )
      r = lastRow;  // half the time. on the bottom
    else
      r = 0;        // the other half, on the top   
  }
  else
  { // set on left or right at any column
    r = rand() % lastRow;
	
	if(r == 0)      // avoid upper right and left corner exits
	  r++;
    if(r == lastRow)
      r--;          // avoid  lower left and  lower right exits
    
	if(rand() % 2 == 0 )
      c = lastCol;  // half the time in the right column
    else
      c = 0;        // the other half, put on left
  }

  rectangle[r][c] = intersectionChar;
}


grid::grid(int totalRows, int totalCols,
			     int startRow, int startCol,
			     int startDirection)
{
  // Check that the boundaries are okay.
  assert(totalRows <= maxRows);
  assert(totalRows > 0);
  assert(totalCols <= maxCols);
  assert(totalCols > 0);
  // Check the initial position of the mover is within the grid
  lastRow = totalRows-1;
  lastCol = totalCols-1;
  assert(startRow >= 0);
  assert(startCol >= 0);
  assert(startRow <= lastRow);
  assert(startCol <= lastCol);

  showPath = 1;   // Show path when 1, when it's 0 keep the intersection visible

  int r, c;
  for(r = 0; r <= lastRow; r++)
	 for(c = 0; c <= lastCol; c++)
		rectangle[r][c] = intersectionChar;

  currentRow = startRow;
  currentCol = startCol;
  facing = startDirection;
  setIcon();
  rectangle[currentRow][currentCol] = icon;
}


// -accessors

int grid::row() const
{
  return currentRow;
}


int grid::column() const
{
  return currentCol;
}


int grid::nRows()  const
{ // lastRow is the number of the last row as in 0..lastRow
  // so the total number of rows is one more than that
  return lastRow+1;
}


int grid::nColumns()  const
{ // lastCol is the number of the last colukmn as in 0..lastCol
  // so the total number of columns is one more than that
  return lastCol+1;
}

bool grid::frontIsClear() const
{
  switch (facing) {
	 case north :
		  if(currentRow == 0)
			 return 0;
		  else
			 if(rectangle [currentRow - 1] [currentCol] == blockChar)
				 return 0;
			 else
				 return 1;
	 case east :
		  if(currentCol == lastCol)
			 return 0;
		  else
			 if(rectangle [currentRow] [currentCol+1] == blockChar)
				 return 0;
			 else
				 return 1;
	 case south :
		  if(currentRow == lastRow)
			 return 0;
		  else
			 if(rectangle [currentRow + 1] [currentCol] == blockChar)
				 return 0;
			 else
             return 1;
    case west :
        if(currentCol == 0)
          return 0;
        else
          if(rectangle [currentRow] [currentCol-1] == blockChar)
				 return 0;
          else
             return 1;
  }
  return 1;
}

bool grid::rightIsClear() const
{
  switch (facing) {
	 case west :
		  if(currentRow == 0)
			 return 0;
		  else
			 if(rectangle [currentRow - 1] [currentCol] == blockChar)
				 return 0;
			 else
				 return 1;
	 case north :
		  if(currentCol == lastCol)
			 return 0;
		  else
			 if(rectangle [currentRow] [currentCol+1] == blockChar)
             return 0;
          else
             return 1;
	 case east :
		  if(currentRow == lastRow)
          return 0;
        else
          if(rectangle [currentRow + 1] [currentCol] == blockChar)
				 return 0;
          else
             return 1;
    case south :
        if(currentCol == 0)
          return 0;
        else
          if(rectangle [currentRow] [currentCol-1] == blockChar)
             return 0;
			 else
             return 1;
  }
  return 1;
}


void grid::display() const
{
  int r, c;
  cout << "The grid: " << endl;
  for(r = 0; r <= lastRow; r++) {
	  for(c = 0; c <= lastCol; c++)
		cout << rectangle[r][c] << ' ';
	 cout << endl;
  }
}


// -modifiers

void grid::turnLeft()
{
  if(facing==north)
	  facing = west;
  else if (facing==east)
	  facing = north;
  else if (facing==south)
	  facing = east;
  else if (facing==west)
 	  facing = south;
  setIcon();
  rectangle [currentRow] [currentCol] = icon;
}

////////////////added by forrest//////////
void grid::turnRight()
{
	turnLeft();
	turnLeft();
	turnLeft();
}

void grid::turnAround()
{
	turnLeft();
	turnLeft();
}
//////end of additions//////////


void grid::setIcon()
{
  if(! (rectangle [currentRow][currentCol] == thingHereChar) ) {
	  switch (facing) {
		 case north :
			icon = '^';
			break;
		 case east :
			icon = '>';
			break;
		 case south :
			icon = 'v';
			break;
		 case west :
			icon = '<';
			break;
	  }
  }
}


void grid::move(int spaces)
{
  assert(spaces > 0);
  int oldRow(currentRow);
  int oldCol(currentCol);

  switch ( facing ) {
	 case north :
		currentRow-=spaces;
      break;
    case east :
		currentCol+=spaces;
      break;
    case south :
      currentRow+=spaces;
      break;
    case west :
      currentCol-=spaces;
		break;
  }
  assert (currentRow >= 0);
  assert (currentCol >= 0);
  assert (currentRow <= lastRow);
  assert (currentCol <= lastCol);

  // Fix the starting intersection

  if(rectangle[oldRow][oldCol] == moverOnThingChar)
	 rectangle[oldRow][oldCol] = thingHereChar;
  else if(rectangle[oldRow][oldCol] == icon && showPath)
     rectangle[oldRow][oldCol] = beenThereChar;
  else
     rectangle[oldRow][oldCol] = intersectionChar;

  int r, c;
  switch(facing) {
  case north:
    for(r = oldRow; r > currentRow; r--) {
		checkForBlock(r-1, currentCol);
		if(rectangle[r][currentCol] != thingHereChar && showPath)
        rectangle[r][currentCol] =  beenThereChar;
    }
    break;
  case east:
	 for(c = oldCol; c < currentCol; c++) {
      checkForBlock(currentRow, c+1);
      if(rectangle[currentRow][c] != thingHereChar && showPath)
		  rectangle[currentRow][c] = beenThereChar;
	 }
  case south:
    for(r = oldRow; r < currentRow; r++) {
		checkForBlock(r+1, currentCol);
      if(rectangle[r][currentCol] != thingHereChar && showPath)
        rectangle[r][currentCol] = beenThereChar;
    }
    break;
  case west:
     for(c = oldCol; c > currentCol; c--) {
		 checkForBlock(currentRow, c-1);
		if(rectangle[currentRow][c] != thingHereChar && showPath)
        rectangle[currentRow][c] = beenThereChar;
     }
  } // end switch

 if(rectangle[currentRow][currentCol] == thingHereChar)
   rectangle[currentRow][currentCol] = moverOnThingChar;
 else
	rectangle[currentRow][currentCol] = icon;
}


void grid::block(int blockRow, int blockCol)
{
   assert(blockRow <= lastRow);
   assert(blockRow >= 0);
   assert(blockCol <= lastCol);
   assert(blockCol >= 0);
   // Can't block the place where the mover is
	assert(rectangle[blockRow][blockCol] != icon);
	// Can't block the place where the an thing has been placed
   assert(rectangle[blockRow][blockCol] != thingHereChar);
   // Now, if everything is alright, put the block down
   rectangle[blockRow][blockCol] = blockChar;
}


void grid::putDown()
{
	rectangle[currentRow][currentCol] = moverOnThingChar;
}

void grid::putDown(int putDownRow, int putDownCol)
{
   assert(putDownRow <= lastRow);
   assert(putDownRow >= 0);
   assert(putDownCol <= lastCol);
   assert(putDownCol >= 0);
   if(rectangle[putDownRow][putDownCol] == blockChar) {
      cout << endl << "Attempt to place block where the mover is at grid("
                   << putDownRow << ", " << putDownCol << ")" << endl;
    cout << "...Program terminating..." << endl;

   }
   else
     rectangle[putDownRow][putDownCol] = thingHereChar;
}

void grid::pickUp()
{
   assert(rectangle[currentRow][currentCol] == thingHereChar ||
          rectangle[currentRow][currentCol] == moverOnThingChar );
	// assert: Program terminated if there was nothing to pickup
   rectangle[currentRow][currentCol] = icon;
}


void grid::toggleShowPath()
{
	if(showPath)
	  showPath = 0;
	else
	  showPath = 1;
}


void grid::checkForBlock(int r, int c)
{
  if(rectangle[r][c] == blockChar) {
	 cout << endl << "Attempt to move through the block at grid("
					  << r << ", " << c << ")" << endl;
	 if(facing == north) // must be moving north
		rectangle[r+1][c] = icon;
	 if(facing == east)  // must be moving east
		rectangle[r][c-1] = icon;
	 if(facing == south) // must be moving south
		rectangle[r-1][c] = icon;
	 if(facing == west)  //  must be moving west
		rectangle[r][c+1] = icon;
	 for(r = 0; r < lastRow; r++) {
		 for(c = 0; c < lastCol; c++)
			cout << rectangle[r][c] << ' ';
		 cout << endl;
	 }
	 cout << "...Program terminating..." << endl;
	 exit(0);
  }
}


