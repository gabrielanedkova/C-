#ifndef _VECTOR_H_
#define  _VECTOR_H_

template <class T>
class Vector
{

public:
	Vector();
	Vector(const Vector& rhs);
	Vector& operator=(const Vector& rhs);
	~Vector();
	T& operator[](const int index);
	int getSize() const;
	int getCapacity() const;
	bool empty();
	void push_back(T value);
	void pop_back();

private:
	void copyData(Vector& rhs);
	void resize();
	T* data;
	int size;
	int capacity;
};

#endif 
/*
template <class T>
Vector<T>::Vector()
{
	size = 0;
	capacity = 0;
}

template <class T>
Vector<T>::Vector(const Vector& rhs)
{
	copyData(rhs);
	size = rhs.size;
	capacity = rhs.capacity;
}

template <class T>
Vector<T>& Vector<T> :: operator=(const Vector& rhs)
{
	if (this != rhs)
	{
		copyData(rhs);
		size = rhs.size;
		capacity = rhs.capacity;
	}
	return this;
}

template <class T>
Vector<T> :: ~Vector()
{
	delete[] data;
}

template <class T>
T& Vector<T> :: operator[](const int index)
{
	return data[index];
}

template <class T>
int Vector<T>::getSize()const
{
	return size;
}

template <class T>
int Vector<T>::getCapacity() const
{
	return capacity;
}

template <class T>
bool Vector<T>::empty()
{
	if (size == 0)
		return true;
	 return false;
}

template <class T>
void Vector<T> :: push_back(T value)
{
	if (size >= capacity)
		resize();
	data[size++] = value;
}

template <class T>
void Vector<T>::pop_back()
{
	size--;
	data[size] = 0;
}

template <class T>
void Vector<T>::copyData(Vector& rhs)
{
	size = rhs.getSize;
	capacity = rhs.getCapacity;
	if (data)
		delete[] data;
	data = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		data[i] = rhs[i];
	}
}

template <class T>
void Vector<T>::resize()
{
	if (data)
	{

		T* temp = new T[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		delete[] data;
		capacity *= 2;
		data = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			data[i] = temp[i];
		}
	}
	else data = new T[5];
}
*/