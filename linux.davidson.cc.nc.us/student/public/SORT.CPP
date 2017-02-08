#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	char filename[20];
	int num[5], temp, i, j;
	cout << "Enter the file to read as input "<<endl;
	cin >> filename;
	ifstream fin(filename);
	fin >> num[0];
	for(i = 1; i < 5; i++)
	  {
	   fin>>num[i];
	   for(j=0; j < i; j++)
	    {
	      if(num[i] > num[j])
		{
		 temp = num[j];
		 num[j] = num[i];
		 num[i] = temp;
		}
	    }
	   }
	for(j=0; j<i; j++)
	   cout << num[j]<<endl;
}
