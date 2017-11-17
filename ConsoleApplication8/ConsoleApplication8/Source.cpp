#include <iostream>
#include <fstream>
#include <string>
#include "Vector.h"

using namespace std;

int main()
{
	
	Vector v;
	v.setName("gabi");
	v.add(4);
	v.add(2);
	v.add(2.2);
	v.add(5);
	v.add(6);
	cout << v;
	Vector v2 = v;
	v2.add(78);
	v.add(78);
	v2.setName("alabala");
	cout << (v2 == v) << endl;
	cout << (v2 + v);
 	cout << v2++;
	
	ofstream out("bin.dat", ios::out|ios::binary);

	system("pause");
	return 0;
}