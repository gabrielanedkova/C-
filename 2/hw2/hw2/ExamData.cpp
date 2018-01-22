#include "ExamData.h"
#include <sstream>

int compareIntegers(const int i1, const int i2);

ExamData::ExamData(const char* name, const int age, const char* subject, const int grade, const char* date) 
	: name(setString(name)), age(age), subject(setString(subject)), grade(grade), date(setString(date))
{
}

ExamData::ExamData(const char* line)
{
	char* temp = new char[1024];
	std::istringstream ss(line);
	ss >> *this;
	delete[] temp;
}

ExamData::ExamData(const ExamData& rhs)
{
	setData(rhs);
}
ExamData& ExamData:: operator= (const ExamData& rhs)
{
	if (this != &rhs)
	{
		setData(rhs);	
	}
	return *this;
}
ExamData::~ExamData()
{
 	delete[] name;
	delete[] subject;
	delete[] date;
}

void ExamData::setData(const ExamData& rhs)
{
	name = setString(rhs.name);
	age = rhs.age;
	subject = setString(rhs.subject);
	grade = rhs.grade;
	date = setString(rhs.date);
}

char* ExamData::setString(const char* source)
{
	int len = strlen(source) + 1;
	char* dest = new char[len];
	strcpy_s(dest, len, source);
	return dest;
}

int ExamData::getGrade()
{
	return grade;
}

std::ostream& operator<<(std::ostream& o, const ExamData& data)
{
	o << data.name << "," << data.age << "," << data.subject << "," << data.grade << "," << data.date << std::endl;
	return o;
}

std::istream& operator>>(std::istream& i, ExamData& data)
{
	char* temp = new char[1024];
	i.getline(temp, 1024, ',');
	data.name = data.setString(temp);
	i.getline(temp, 1024, ',');
	data.age = atoi(temp);
	i.getline(temp, 1024, ',');
	data.subject = data.setString(temp);
	i.getline(temp, 1024, ',');
	data.grade = temp[0] - '0';
	i.getline(temp, 1024, ',');
	data.date = data.setString(temp);
	delete[] temp;
	return i;
}

bool operator<=(const ExamData& e1, const ExamData& e2)
{
	if (strcmp(e1.date, e2.date) <= 0)
		return true;
	return false;
}

bool isBiggerByDate(const ExamData& t, const ExamData& other)
{
	return strcmp(t.date, other.date) >= 0;
}

bool isSmallerByDate(const ExamData& t, const ExamData& other)
{
	return strcmp(t.date, other.date) <= 0;
}

bool isBiggerBySubject(const ExamData& t, const ExamData& other)
{
	return strcmp(t.subject, other.subject) > 0;
}

bool isSmallerBySubject(const ExamData& t, const ExamData& other)
{
	return strcmp(t.subject, other.subject) < 0;
}

bool isBiggerByName(const ExamData& t, const ExamData& other)
{
	return strcmp(t.name, other.name) >= 0;
}

bool isSmallerByName(const ExamData& t, const ExamData& other)
{
	return strcmp(t.name, other.name) <= 0;

}
bool isBiggerByAge(const ExamData& t, const ExamData& other)
{
	return t.age > other.age;
}
bool isSmallerByAge(const ExamData& t, const ExamData& other)
{
	return t.age < other.age;
}

