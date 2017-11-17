#include "dynArr.h"

Vector::Vector()
{
	arr = new int[2];
	size = 0;
	capacity = 0;
}
int Vector::top()
{
	if (size == 0)
		return -1;
	return arr[size - 1];
}

void Vector::pop()
{
	if (size == 0)
		return;
	arr[size - 1] = 0;
	size--;
	if (capacity > 2 * size)
		resize(2 * size);
}

void Vector::push(int num)
{
	if (capacity == size)
		resize(2 * size);
	arr[size] = num;
	size++;
}

void Vector::resize(int newSize)
{
	int* buff = new int[newSize];
	for (int i = 0; i < size; i++)
		buff[i] = arr[i];
	for (int i = size; i < newSize; i++)
		buff[i] = 0;
	delete[] arr;
	arr = buff;
}