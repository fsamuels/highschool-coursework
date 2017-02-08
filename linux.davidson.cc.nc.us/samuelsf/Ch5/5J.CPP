/* Forrest Samuels		CSC 134

	3.2.99

	This program will block off arround a 3 by 3 square and use the & 
to allow objects to be changed within the function.

*/

#include </student/public/grid>
#include <iostream>
using namespace std;

void blockThree(grid & g)
{

	g.block(0, 0);
	g.block(0, 1);
	g.block(0, 2);
	g.block(1, 0);
	g.block(1, 2);
	g.block(2, 0);
	g.block(2, 1);
	g.block(2, 2);

}

int main()
{
	grid tarpit(3, 3, 1, 1, east);
	blockThree(tarpit);
	tarpit.display();
	return 0;
}
