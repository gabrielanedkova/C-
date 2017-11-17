/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gabriela Nedkova
* @idnumber 45097
* @task 1
* @compiler VC
*
*/
#include <iostream>
using namespace std;

template <class T>
class Stack
{
public:
	Stack();
	Stack(const Stack & rhs);
	Stack& operator=(const Stack<T>& rhs);
	~Stack();
	T& top();
	void pop();
	void push(const T&);
	bool isEmpty();
	int getSize(){ return size; };
	void changeElement(const char* oldOp, const char* newOp);
	void cd() { for (int i = 0; i < size; i++) cout << data[i] << " "; cout << " ///// " << size << " " << capacity << endl; };

private:

	void resize(int newSize);
	void copyData(const Stack& rhs);

private:
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
Stack<T>::Stack(const Stack& rhs)
{
	size = 0;
	capacity = 0;
	data = nullptr;
	copyData(rhs);
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs)
{
	if (this != &rhs)
	{
		copyData(rhs);
	}
	return *this;
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
template <class T>
void Stack<T>::copyData(const Stack& rhs)
{
	size = rhs.size;
	capacity = rhs.capacity;
	delete[] data;
	data = new T[capacity];
	for (int i = 0; i <= size; i++)
		data[i] = rhs.data[i];
}

template <class T>
void Stack<T>::changeElement(const char* oldOp, const char* newOp)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(data[i], oldOp) == 0)
		{
			strcpy_s(data[i], sizeof(newOp), newOp);
		}
	}
}
