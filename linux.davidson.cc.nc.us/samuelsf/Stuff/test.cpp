#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

void main()
{

	char filename[20],username[20],pass[10], command[4];
	//string filename,username,pass,command;
   	cout << "enter input file" <<endl;
	cin >> filename;
	ifstream fin(filename);
	fin >> username >> pass;
	cout << username << pass;
	command = "who";
	//cout << command;
	system (command);
	//system("uname");
	//system("uname -a");
	cout << endl;
}

