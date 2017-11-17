#include <iostream>
#include "dynArr.h"
using namespace std;

int main()
{
	Vector a;
	cout << a.top() << endl;
	a.push(3);
	cout << a.top() << endl;
	a.push(7);
	cout << a.top() << endl;
	a.push(5);
	cout << a.top() << endl;
	a.push(2);
	cout << a.top() << endl;
	a.push(8);
	cout << a.top() << endl;
	a.push(0);
	cout << a.top() << endl;
	a.push(313);
	cout << a.top() << endl;
	a.pop();
	cout << a.top() << endl;
	a.pop();
	cout << a.top() << endl;
	a.pop();

	cout << a.top() << endl;
	a.pop();
	cout << a.top() << endl;
	a.pop();

	cout << a.top() << endl;
	a.pop();

	cout << a.top() << endl;
	a.pop();

	cout << a.top() << endl;
	a.pop();

	cout << a.top() << endl;



	system("pause");
}