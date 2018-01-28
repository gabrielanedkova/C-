#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const size_t MAX_FIELD_LENGTH = 30;
class Person {
	char firstName[MAX_FIELD_LENGTH + 1]; // Собствено име
	char lastName[MAX_FIELD_LENGTH + 1];  // Фамилия
	char email[MAX_FIELD_LENGTH + 1];     // Имейл
	unsigned int age;                     // Възраст

public:
	Person& operator=(const Person&  rhs)
	{
		age = rhs.age;
		strcpy(email, rhs.email);
		strcpy(lastName, rhs.lastName);
		strcpy(firstName, rhs.firstName);

		return *this;
	}
	int getAge(){
		return age;
	}
	friend istream& operator>>(istream& i, Person& p)
	{
		i >> p.firstName >> p.lastName >> p.age >> p.email;
		return i;
	}
};

int countLines(ifstream& i)
{
	int cnt = 0;
	string line;
	while (getline(i, line))
		++cnt;
	return cnt;
}
void sort(Person*& arr, int size)
{
	int maxAge = 0;
	for (int i = 0; i < size; ++i)
	{
		int age = arr[i].getAge();
		if (age > maxAge)
			maxAge = age;
	}
	++maxAge;
	int* ages = new int[maxAge];
	memset(ages, 0, maxAge * sizeof(int));
	for (int i = 0; i < size; ++i)
	{
		++ages[arr[i].getAge()];
	}
	
	for (int i = 1; i < maxAge; ++i)
	{
		if (ages[i] != 0)
			ages[i] = ages[i - 1] + ages[i];
		else ages[i] = ages[i - 1];
	}
	for (int i = 0; i < maxAge; ++i)
		cout << ages[i];
	Person* temp = new Person[size];
	for (int i = size - 1; i >= 0; --i)
	{
		int age = arr[i].getAge();
		int index = ages[age] - 1;
		temp[index] = arr[i];
		--ages[age];

	}
	delete[] arr;
	arr = temp;
	delete[] ages;
}

class Tree
{
	int* arr;
	int size;
	void constructTree(int index, int start, int end, int* personArr)
	{
		if (start > end)
			return;
		int middle = (end + start ) / 2;
		
		arr[index] = personArr[middle];
		constructTree(2 * index + 2, start, middle - 1, personArr);
		constructTree(2 * index + 1, middle + 1, end, personArr);
	}

public:
	Tree(int size, int* personArr)
	{
		this->size = size;
		arr = new int[size];
		constructTree(0, 0, size - 1, personArr);
	}
	void print()
	{
		cout << endl;
		for (int i = 0; i < size; ++i)
			cout << arr[i] << " ";
	}
};
int main(int argc, char** argv)
{
	
	ifstream file("gabi.txt");
	string str;
	int cnt = countLines(file);
	file.clear();
	file.seekg(0,file.beg);
	Person* arr = new Person[cnt];

	for (int i = 0; i < cnt; i++)
	{
		file >> arr[i];
	}
	file.close();
	sort(arr, cnt);
	delete[] arr;

	int test[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	Tree t(14, test);
	t.print();
	
	return 0;
}