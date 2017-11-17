#include <iostream>
#include <vector>
#include "Header.h"


using namespace std;

void test1(int* a) {
	a[0] = 1;
}

void test2(int a[]) {
	a[1] = 2;
}

void test3(int *&a) {
	a[2] = 3;
}

int main() {
	vector<int> v = { 2, 3, 4 };
	v.push_back(3);
	cout << v.back() << endl;
	int *a = new int[3];
	a[0] = 0;
	a[1] = 0;
	a[2] = 0;

	test1(a);
	test2(a);
	test3(a);

	cout << a[0] << endl;
	cout << a[1] << endl;
	cout << a[2] << endl;

	Person p(233);
	Person person(300);
	person.fr = p;
	cout << person.age;


	system("pause");
}