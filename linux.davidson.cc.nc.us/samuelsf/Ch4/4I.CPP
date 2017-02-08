/* Forrest Samuels		CSC 134
*
*  Feburary 14, 1999
*
*  This program will construct an obstacle course and place down an O.
*  The  mover will then maneuver teh course and pick up the O.
*/

#include "/student/public/grid"

void main()
{

//Input Section

	
//Process Section

	grid grid(6, 13, 4, 8, north);
	grid.putDown(4, 3);
	grid.block(0, 5);
	grid.block(1, 5);
	grid.block(3, 5);
	grid.block(4, 5);
	grid.block(1, 7);
	grid.block(2, 7);
	grid.block(3, 7);
	grid.block(4, 7);
	grid.block(5, 7);
	grid.display();

	grid.move(4);
	grid.turnLeft();
	grid.move(2);
	grid.turnLeft();
	grid.move(2);
	grid.turnLeft();
	grid.turnLeft();
	grid.turnLeft();
	grid.move(3);
	grid.turnLeft();
	grid.move(2);
	grid.pickUp();
	grid.move(1);
	        
//Output Section

	grid.display();

}
