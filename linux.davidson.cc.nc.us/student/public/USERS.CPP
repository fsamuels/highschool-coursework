#include <fstream>
#include <iostream>
#include "/student/public/string"
using namespace std;

void main()
{
	int i;
	char filename[20];
	string data;
	cout << "Please enter file to read " << endl;
	cin >> filename;
	ifstream fin(filename);
	i = 0;
	while (fin>>data)
	{
		// More stuff to come
		cout << data << " " << i << endl;
		i++;
	}
}
