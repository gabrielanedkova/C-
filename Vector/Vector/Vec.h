#ifndef _VECTOR_H_
#define _VECTOR_H_

class Vec
{
private:
	int* data;
	int capacity;
	int size;
	void resize();

public:
	Vec();
	Vec(const Vec& rhs);
	Vec& operator=(const Vec& rhs);
	~Vec();
	int getSize() const;
	int getCapacity() const;
	void push_back(int value);
	void pop_back();
	void display();
};

#endif