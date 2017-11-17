#include <iostream>

using namespace std;

template <class T>
class Stack
{
public:
	Stack();
	~Stack();
	T& top();
	void pop();
	void push(const T&);
	bool isEmpty();
	void getSize(){ cout << size << " " << capacity << endl; }
private:
	void resize(int newSize);
	T* data;
	int size;
	int capacity;
};

template <class T>
Stack<T>::Stack()
{
	size = 0;
	capacity = 2;
	data = new T[capacity];
}

template <class T>
Stack<T>::~Stack()
{
	delete[] data;
}

template <class T>
bool Stack<T> ::isEmpty()
{
	if (size <= 0)
		return true;
	return false;
}

template <class T>
T& Stack<T>::top()
{
	if (!isEmpty())
	{
		return data[size - 1];
	}
}
template <class T>
void Stack<T>::push(const T& value)
{
	data[size] = value;
	size++;
	if (size >= capacity)
		resize(size * 2);
}
template <class T>
void Stack<T>::pop()
{
	size--;
	if (size > 2 && size * 2 < capacity)
		resize(size * 2);
}
template <class T>
void Stack<T>::resize(int newCapacity)
{
	T* newData = new T[newCapacity];
	for (int i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	capacity = newCapacity;
}