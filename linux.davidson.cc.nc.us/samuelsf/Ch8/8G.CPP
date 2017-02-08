/*	Forrest Samuels

	CSC 134

	April 12, 1999

	8g.cpp

	This program will surround a grid with cookies.
*/
#include </student/public/grid>

void surroundGrid(grid & myGrid)
{
	while((myGrid.nColumns() - 1) != myGrid.column())
	{
		myGrid.putDown();
		myGrid.move(1);
	}

	myGrid.turnLeft();

	while(myGrid.row() != 0)
	{
		myGrid.putDown();
		myGrid.move(1);
	}

	myGrid.turnLeft();

	while(myGrid.column() != 0)
	{
		myGrid.putDown();
		myGrid.move(1);
	}

	myGrid.turnLeft();

	while((myGrid.nRows() - 1) != myGrid.row())
	{
		myGrid.putDown();
		myGrid.move(1);
	}
}

void main()
{
	grid myGrid(4, 10, 3, 0, east);
	surroundGrid(myGrid);
	myGrid.display();
}
