/* Forrest Samuels		CSC 134

	3.2.99

	This program will block off a 5x5 grid and then put "cookies"
arround the inner row/columns.
*/

#include </student/public/grid>
#include <iostream>
using namespace std;

void modifyGrid(grid & g)
{

	g.putDown(1, 1);
	g.putDown(1, 2);
	g.putDown(1, 3);
	g.putDown(2, 1);
	g.putDown(2, 3);
	g.putDown(3, 1);
	g.putDown(3, 2);
	g.putDown(3, 3);

	g.block(0, 0);
	g.block(0, 1);
	g.block(0, 2);
	g.block(0, 3);
	g.block(0, 4);

	g.block(1, 0);
	g.block(2, 0);
	g.block(3, 0);
	
	g.block(1, 4);
	g.block(2, 4);
	g.block(3, 4);

	g.block(4, 0);
	g.block(4, 1);
	g.block(4, 2);
	g.block(4, 3);
	g.block(4, 4);

}

int main()
{
	grid tarpit(5, 5, 2, 2, north);
	modifyGrid(tarpit);
	tarpit.display();
	return 0;
}
