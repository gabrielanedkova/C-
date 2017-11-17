#include <iostream>
#include "Vec.h"

Vec::Vec()
{
	size = 0;
	capacity = 0;
	data = nullptr;
}
Vec::Vec(const Vec& rhs)
{
	size = rhs.size;
	capacity = rhs.capacity;
	data = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		data[i] = rhs.data[i];
	}
}
Vec& Vec::operator=(const Vec& rhs)
{
	if (this != &rhs)
	{
		size = rhs.size;
		capacity = rhs.capacity;
		data = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			data[i] = rhs.data[i];
		}
	}
	return *this;
}
Vec::~Vec()
{
	delete[] data;
}
int Vec::getSize() const
{
	return size;
}
int Vec::getCapacity() const
{
	return capacity;

}
void Vec::push_back(int value)
{
	size++;
	if (size > capacity)
		resize();
	data[size - 1] = value;

}
void Vec:: pop_back()
{
	if (size > 0)
		size--;
}

void Vec::resize()
{
	if (data){
		capacity += capacity / 2 + 1;
		int* temp = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
	}
	else {
		data = new int[1];
		capacity++;
	}

}

void Vec::display()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << " ";
	}
}

