#include "Vector.h"
#include <iostream>
const int INITIAL_CAPACITY = 4;
Vector::Vector() :size(0), capacity(INITIAL_CAPACITY), data(nullptr), name(nullptr)
{
}

Vector::Vector(const Vector& rhs) : size(0), capacity(INITIAL_CAPACITY), data(nullptr), name(nullptr)
{
	copy(rhs);
}

void Vector::copy(const Vector& rhs){

	setSize(rhs.size);
	setCapacity(rhs.capacity);
	setName(rhs.name);
	setData(rhs.data, rhs.capacity, rhs.size);
	
}

char* Vector::getName()const{
	if (name){
		int len = strlen(this->name);
		char* copy = new char[len + 1];
		strcpy_s(copy, len + 1, name);
		return copy;
	}
	return nullptr;
}
double* Vector::getData()const{
	if (data){
		double* copy = new double[size];
		for (int i = 0; i < size; i++)
			copy[i] = data[i];
		return copy;
	}
	return nullptr;
}
void Vector::setName(const char* name){
	if (name)
	{
		int len = strlen(name);
		delete[] this->name;
		this->name = new(std::nothrow) char[len + 1];
		if (name)
			strcpy_s(this->name, len + 1, name);
	}
}

Vector& Vector::operator=(const Vector& rhs){
	if (this != &rhs)
	{
		copy(rhs);
	}
	return *this;
}

void Vector::setSize(const int size){
	this->size = size;
}
void Vector::setCapacity(const int capacity){
	this->capacity = capacity;
}
void Vector::setData(const double* data, const int capacity, const int size){
	if (data){
		delete[] this->data;
		double* arr = new double[capacity];
		for (int i = 0; i < size; i++)
			arr[i] = data[i];
		this->data = arr;
	}

}
int Vector::getSize()const{
	return size;
}

int Vector::getCapacity()const{
	return this->capacity;
}


void Vector::add(const double value){
	if (!data)
		data = new(std::nothrow) double[capacity];
	if (capacity == size){
		resize(size * 2);
	}
	data[size++] = value;
}

void Vector::resize(const int size){
	capacity = size;
	double* arr = new double[capacity];
	for (int i = 0; i < this->size; i++)
		arr[i] = data[i];
	delete[] data;
	data = arr;
}

void Vector::del(const int index){
	if (index >= 0 && index < size){
		double* copy = new double[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++){
			if (i == index)
				i++;
			copy[j] = data[i];
			data[i] = 0;
			data[j] = copy[j];
			j++;
		}
	}
	size--;
}


double Vector::operator[] (const int index)const{

	if (index >= 0 && index < size){
		return data[index];
	}
}
double& Vector::operator[] (const int index)
{

	if (index >= 0 && index < size)
		return data[index];

}
Vector::~Vector(){
	delete[] name;
	delete[] data;
}

Vector& Vector::operator+=(const Vector& rhs){
	int s = size;
	if (size > rhs.size)
		s = rhs.size;
	for (int i = 0; i < s; i++){
		data[i] += rhs.data[i];
	}
	return *this;
}
Vector& Vector::operator-=(const Vector& rhs)
{
	int s = size;
	if (size > rhs.size)
		s = rhs.size;
	for (int i = 0; i < s; i++){
		data[i] -= rhs.data[i];
	}
	return *this;
}
Vector& Vector::operator*=(const Vector& rhs)
{
	int s = size;
	if (size > rhs.size)
		s = rhs.size;
	for (int i = 0; i < s; i++){
		data[i] += rhs.data[i];
	}
	return *this;
}
Vector& Vector::operator/=(const Vector& rhs){
	int s = size;
	if (size > rhs.size)
		s = rhs.size;
	for (int i = 0; i < s; i++){
		data[i] /= rhs.data[i];
	}
	return *this;
}
Vector Vector::operator-(){
	Vector v(*this);
	for (int i = 0; i < v.size; i++){
		v.data[i] = -data[i];
	}
	return v;
}
Vector Vector::operator+(){
	Vector v(*this);
	for (int i = 0; i < v.size; i++){
		v.data[i] = data[i];
	}
	return v;
}
Vector Vector::operator*(int num){
	Vector v(*this);
	for (int i = 0; i < v.size; i++){
		v.data[i] *= num;
	}
	return v;
}
Vector Vector::operator/(int num){
	Vector v(*this);
	for (int i = 0; i < v.size; i++){
		v.data[i] /= num;
	}
	return v;
}
Vector& Vector::operator++(){
	for (int i = 0; i < size; i++){
		data[i]++;
	}
	return *this;
}
Vector& Vector::operator--(){
	for (int i = 0; i < size; i++){
		data[i]--;
	}
	return *this;
}
Vector Vector::operator++(int){
	Vector temp(*this);
	++(*this);
	return temp;
}
Vector Vector::operator--(int){
	Vector temp(*this);
	--(*this);
	return temp;
}

Vector operator+(const Vector& v1, const Vector& v2){
	Vector v(v1);
	v += v2;
	return v;
}

std::ostream& operator<<(std::ostream& out, const Vector& v){
	out << "name: " << v.name << std::endl << "data: ";
	for (int i = 0; i < v.size; i++){
		out << i << ": " << v.data[i] << ", ";
	}
	return out;
}

std::istream& operator>>(std::istream& in, Vector& v){
	int size;
	in >> size;
	if (size > 0){
		v.size = size;
		v.capacity = size * 2;
		delete[] v.data;
		v.data = new double[size];
	}
	for (int i = 0; i < size; i++)
		in >> v.data[i];
	return in;
}

bool operator==(const Vector& v1, const Vector& v2){
	if (v1.getSize() != v2.getSize())
		return false;
	for (int i = 0; i < v1.getSize(); i++){
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}
bool operator!=(const Vector& v1, const Vector& v2)
{
	return !(v1==v2);
}
bool operator>=(const Vector& v1, const Vector& v2)
{
	return !(v1 < v2);
}
bool operator<=(const Vector& v1, const Vector& v2)
{
	return !(v1 > v2);
}
bool operator>(const Vector& v1, const Vector& v2)
{
	return v2 < v1;
}
bool operator<(const Vector& v1, const Vector& v2)
{
	int v1Size = v1.getSize();
	int v2Size = v2.getSize();
	if (v1Size > v2Size)
		return false;
	else if (v1Size < v2Size)
		return true;
	for (int i = 0; i < v1Size; i++){
		if (v1[i] < v2[i])
			return true;
		if (v1[i] > v2[i])
			return false;
	}
	return false;
}