#include <iostream>

using namespace std;

class Stack
{
public:
	Stack();
	Stack(const Stack &rhs);
	~Stack();
	char* top();
	void pop();
	void push(char*);
	bool isEmpty();
	int getSize(){ return size; }
	void display() { for (int i = 0; i < size; i++) cout << data[i] << " "; }
private:
	void copy(const char* str, int index);
	void resize(int newSize);

	char** data;
	int size;
	int capacity;
};