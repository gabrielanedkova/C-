#include <iostream>
#include "Vec.h"
#include <vector>


int main()
{
	Vec v;
	v.push_back(1);
	v.display();

	v.push_back(4);
	v.display();

	v.push_back(23);
	v.display();

	v.push_back(65);
	v.push_back(1);
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();

	v.display();
	
	system("pause");
}