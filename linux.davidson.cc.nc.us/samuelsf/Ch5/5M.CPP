/* Forrest Samuels		CSC 134

	3.5.99

	This program will jump some hurdles using functions.
*/

#include </student/public/grid>
using namespace std;

void jumpHurdle(grid & g)
{
	g.move(2);
	g.turnLeft();
	g.move(1);
	g.turnLeft();
	g.turnLeft();
	g.turnLeft();
	g.move(2);
	g.turnLeft();
	g.turnLeft();
	g.turnLeft();
	g.move(1);
	g.turnLeft();

}

grid initializedGrid()
{
	grid g = grid(4, 22, 2, 0, east);
	g.block(2, 3);
	g.block(2, 7);
	g.block(2, 11);
	g.block(2, 15);
	g.block(2, 19);
	return g;
}

int main()
{	
	grid jumper = initializedGrid();
	
	jumper.display();
	jumpHurdle(jumper);
	jumpHurdle(jumper);
	jumpHurdle(jumper);
	jumpHurdle(jumper);
	jumpHurdle(jumper);
	jumper.display();
	return 0;
}
