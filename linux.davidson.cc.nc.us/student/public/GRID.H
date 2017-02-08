// File: grid
// From: Computing Fundamentals with C++, Second Edition
//       Rick Mercer, Franklin, Beedle, and Associates
// DRAFT += DRAFT += DRAFT += DRAFT += DRAFT += DRAFT +=
// I plan to mak the implementation morew object-oriented  
//    (a vector of vectors where each element is an intersection



#ifndef GRID_H
#define GRID_H
const int maxRows = 22;
const int maxCols = 36;

///////////////////////////////////////////////////////////////////////////
// The grid class definition //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

class grid {
public:
  // --constructors
  grid();
  // Construct a
  grid(int totalRows, int totalCols);
  grid(int totalRows, int totalCols,
       int startRow, int startCol,
       int startDirection);

// Modifiers
  void move(int spaces);
  void turnLeft();
  void putDown();
  void putDown(int putDownRow, int putDownCol);

  void toggleShowPath();
  void pickUp();
  void block(int blockRow, int blockCol);
  // pre:  The intersection at (blockRow, blockCol) has nothing at all
  //       on it, not even the mover
  // post: The intersection at (blockRow, blockCol) is blocked. The
  //       mover cannot move into this intersection

// -- Accessors
  bool frontIsClear() const;
  bool rightIsClear() const;
  int row() const;
  int column() const;
  int nRows() const;
  int nColumns() const;
  void display() const;

private:
  int lastRow;     // the number of the last row
  int lastCol;     // the number of the last column
  char rectangle[maxRows][maxCols];
  int currentRow, currentCol;  // where the mover is
  char icon;                   // the symbol in the currentRow, currentCol
  int facing;      // 0 == north, 1 == east, 2 == south, and 3 == west
  int showPath;    // whether or not the path is shown
  void checkForBlock(int r, int c);  // used by the implementation only
  void setIcon();  // used in implementation only
};

#endif // GRID_H
