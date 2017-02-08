/* Forrest Samuels		CSC 134
*
*  Feburary 9, 1999
*
*  This program will hide a message in 5 words using 1 letter from each
*  word.
*/

#include <iostream>
#include <string>
using namespace std;

void main()
{
	string word1, word2, word3, word4, word5, word; 
	int n1, n2, n3, n4, n5;

//Input Section

	cout << "Enter five words:  ";
	cin >> word1 >> word2 >> word3 >> word4 >> word5;
	cout << "Enter five integers: ";
	cin >> n1 >> n2 >> n3 >> n4 >> n5;
	
//Process Section
	
	word1 = word1[n1];
	word2 = word2[n2];
	word3 = word3[n3];
	word4 = word4[n4];
	word5 = word5[n5];
	word = word1 + word2 + word3 + word4 + word5;
 
//Output Section

	cout << "Secret message: " << word << endl;

}
