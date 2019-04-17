#include "Vehicle.h"
#include <iostream>


Vehicle::Vehicle()
{
	char fileName[]= "gabi.txt";
	number = new char[15];
	model = new char[30];
	ownerName = new char[30];
	std::ifstream i(fileName);
	i >> number >> year >> model >> ownerName;

	std::cout <<  number << " " << year << " " << model << " " << ownerName;
}

Vehicle::Vehicle(const Vehicle & source)
{
	copyStr(number, source.number);
	copyStr(model, source.model);
	copyStr(ownerName, source.ownerName);
	this->year = source.year;
}

Vehicle & Vehicle::operator=(const Vehicle & source)
{
	if (&source != this) 
	{
		delete[] number;
		delete[] model;
		delete[] ownerName;
		copyStr(number, source.number);
		copyStr(model, source.model);
		copyStr(ownerName, source.ownerName);
		this->year = source.year;
	}
	return *this;
}



Vehicle::~Vehicle()
{
	std::ofstream o("new.txt", std::ios::app);
	o << number << " " << year << " " << model << " " << ownerName << '\n';
	o.close();
	delete[] number;
	delete[] model;
	delete[] ownerName;
}

bool operator<(const Vehicle & left, const Vehicle & right)
{
	return left.year < right.year;
}

char * Vehicle::getNumber()
{
	return number;
}

void Vehicle::setNumber(char* number)
{
	delete[] this->number;
	this->number = new char[15];
	copyStr(this->number, number);
}

void Vehicle::setYear(int year)
{
	this->year = year;
}

void Vehicle::copyStr(char *& copy, char * original)
{
	if (original != nullptr)
	{
		delete[] copy;
		int len = strlen(original) + 1;
		copy = new char[len];
		for (int i = 0; i < len; ++i)
		{
			copy[i] = original[i];
		}
	}

}

///////////////////////////

#pragma once
#include<fstream>
class Vehicle
{

public:
	Vehicle();
	Vehicle(const Vehicle& source);
	Vehicle& operator= (const Vehicle& source);
	~Vehicle();

	friend bool operator< (const Vehicle& left, const Vehicle& right);
	char* getNumber();
	void setNumber(char* number);
	void setYear(int year);


private:
	char* number;
	int year;
	char* model;
	char* ownerName;

	void copyStr(char*& copy, char* original);

};

////////////////////////////////////

#include <iostream>
#include <fstream>
#include "Vehicle.h"

using namespace std;


int main() {

	Vehicle v;
	cout << endl;
	Vehicle b = v;
	char n[] = "new";
	v.setNumber(n);
	v.setYear(2000);
	cout << (v<b);
	system("pause");
}
///////////


friend Cents operator+(const Cents &c1, const Cents &c2);
Cents operator+(const Cents &c1, const Cents &c2)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return Cents(c1.m_cents + c2.m_cents);
}



friend std::ostream& operator<< (std::ostream &out, const Point &point);

 
std::ostream& operator<< (std::ostream &out, const Point &point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")"; // actual output done here
 
    return out; // return std::ostream so we can chain calls to operator<<
}


friend std::ostream& operator<< (std::ostream &out, const Point &point);
    friend std::istream& operator>> (std::istream &in, Point &point);
};
 
std::ostream& operator<< (std::ostream &out, const Point &point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";
 
    return out;
}
 
std::istream& operator>> (std::istream &in, Point &point)
{
    // Since operator>> is a friend of the Point class, we can access Point's members directly.
    // note that parameter point must be non-const so we can modify the class members with the input values
    in >> point.m_x;
    in >> point.m_y;
    in >> point.m_z;
 
    return in;
}

Digit& Digit::operator++()
{
    // If our number is already at 9, wrap around to 0
    if (m_digit == 9)
        m_digit = 0;
    // otherwise just increment to next number
    else
        ++m_digit;
 
    return *this;
}

int& operator[] (const int index);
};
 
int& IntList::operator[] (const int index)
{
    assert(index >= 0 && index < 10);
 
    return m_list[index];

