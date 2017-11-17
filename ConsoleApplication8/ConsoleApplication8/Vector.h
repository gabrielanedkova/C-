#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <fstream>
class Vector{
public:
	Vector();
	Vector(const Vector& rhs);
	Vector& operator=(const Vector& rhs);
	~Vector();

	char* getName()const;
	void setName(const char* name);
	int getSize()const;
	int getCapacity()const;
	double* getData()const;
	void add(const double value);
	void resize(const int size);
	void del(const int index);
	void copy(const Vector& rhs);

	Vector& operator+=(const Vector& rhs);
	Vector& operator-=(const Vector& rhs);
	Vector& operator*=(const Vector& rhs);
	Vector& operator/=(const Vector& rhs);
	Vector operator-();
	Vector operator+();
	Vector operator*(int num);
	Vector operator/(int num);
	Vector& operator++();
	Vector& operator--();
	Vector operator++(int);
	Vector operator--(int);

	double operator[] (const int index)const;
	double& operator[] (const int index);


	friend std::ostream& operator<<(std::ostream& out, const Vector& v);
	friend std::istream& operator>>(std::istream& in, Vector& v);
private:
	void setSize(const int size);
	void setCapacity(const int capacity);
	void setData(const double* data, const int capacity, const int size);

private:
	int size;
	int capacity;
	double* data;
	char* name;

};

bool operator==(const Vector& v1, const Vector& v2);
bool operator!=(const Vector& v1, const Vector& v2);
bool operator>=(const Vector& v1, const Vector& v2);
bool operator<=(const Vector& v1, const Vector& v2);
bool operator>(const Vector& v1, const Vector& v2);
bool operator<(const Vector& v1, const Vector& v2);

Vector operator+(const Vector& v1, const Vector& v2);


#endif