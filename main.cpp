#include<iostream>
#include <fstream>
#include  "Queue.h"

using namespace std;
int main()
{
	Tree a;
	a.insert(3);
	a.insert(4);
	a.insert(6);
	a.insert(42);
	a.insert(43);
	a.insert(2);
	a.insert(22 );
	a.insert(-1);
	cout << endl;
	a.printPretty();
	cout << endl << a.height() << endl;
	cout << endl << a.cntLeafes() << endl;
	cout << endl << a.elCnt() << endl;
	cout << endl << a.subtreeWithNelements(1)<< endl;

	//ofstream ofile("file.txt");
	//ofile << "(32(34(12()())(23()())(33()()))";
	//ofile.close();
	ifstream ifile ("file.txt");
	char c;
	int num = 0;
	while (ifile >> c)
	cout << c <<" "; 
	ifile.close();
	system("pause");
}