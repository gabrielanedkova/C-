#include <iostream>
#include "Header.h"


Stack::Stack()
{
	size = 0;
	capacity = 2;
	data = new char* [capacity];
}

Stack::Stack(const Stack& rhs)
{
	size = rhs.size;
	capacity = rhs.capacity;
	delete[] data;
	data = new char*[capacity];
	for (int i = 0; i < size; i++)
		data[i] = rhs.data[i];

}

Stack::~Stack()
{
	delete[] data;
}

void Stack::copy(const char* str, int index)
{
	if (str == nullptr)
		return;
	int len = strlen(str);
	char* arr = new char[len + 1];
	if (!arr)
		return;
	strcpy_s(arr, len + 1, str);
	delete[] data[index];
	data[index] = arr;
}

bool Stack::isEmpty()
{
	if (size <= 0)
		return true;
	return false;
}

char* Stack::top()
{
	if (!isEmpty())
	{
		return data[size - 1];
	}
	return "The stack is empty!";
}

void Stack::push(char* value)
{
	data[size] = value;
	size++;
	if (size >= capacity)
		resize(size * 2);
}

void Stack::pop()
{
	size--;
	if (size > 2 && size * 2 < capacity)
		resize(size * 2);
}

void Stack::resize(int newCapacity)
{
	char** newData = new char*[newCapacity];
	for (int i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	capacity = newCapacity;
}

