/* Forrest Samuels		CSC 134
*
*  Feburary 14, 1999
*
*  This program will construct a hurdle course and have the mover(runner) 
*  jump them as illustrated in the book.
*/

#include "/student/public/grid"

void main()
{

//Input Section

	
//Process Section

	grid grid(4, 23, 2, 0, east);
	grid.block(2, 3);
	grid.block(2, 7);
	grid.block(2, 11);
	grid.block(2, 15);
	grid.block(2, 19);
	grid.display();
		        
	grid.move(2);
	grid.turnLeft();
	grid.move(1);
	grid.turnLeft();
	grid.turnLeft();
	grid.turnLeft();
	grid.move(2);
	grid.turnLeft();
	grid.turnLeft();
	grid.turnLeft();
	grid.move(1);
	grid.turnLeft();

 	grid.move(2);
        grid.turnLeft();
        grid.move(1);
        grid.turnLeft();
        grid.turnLeft();
        grid.turnLeft();
        grid.move(2);
        grid.turnLeft();
        grid.turnLeft();
        grid.turnLeft();
        grid.move(1);
        grid.turnLeft();

 	grid.move(2);
        grid.turnLeft();
        grid.move(1);
        grid.turnLeft();
        grid.turnLeft();
        grid.turnLeft();
        grid.move(2);
        grid.turnLeft();
        grid.turnLeft();
        grid.turnLeft();
        grid.move(1);
        grid.turnLeft();

 	grid.move(2);
        grid.turnLeft();
        grid.move(1);
        grid.turnLeft();
        grid.turnLeft();
        grid.turnLeft();
        grid.move(2);
        grid.turnLeft();
        grid.turnLeft();
        grid.turnLeft();
        grid.move(1);
        grid.turnLeft();	

 	grid.move(2);
        grid.turnLeft();
        grid.move(1);
        grid.turnLeft();
        grid.turnLeft();
        grid.turnLeft();
        grid.move(2);
        grid.turnLeft();
        grid.turnLeft();
        grid.turnLeft();
        grid.move(1);
        grid.turnLeft();

	grid.move(2);

//Output Section

	grid.display();

}
