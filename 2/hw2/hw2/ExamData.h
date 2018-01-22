#ifndef EXAM_DATA_H
#define EXAM_DATA_H
#include <iostream>

class ExamData
{
public:
	ExamData(){};
	ExamData(const char* line);
	ExamData(const char* name, const int age, const char* subject, const int grade, const char* date);
	ExamData(const ExamData& rhs);
	ExamData& operator=(const ExamData& rhs);
	~ExamData();
	int getGrade();
	friend bool isBiggerByName(const ExamData& t, const ExamData& other);
	friend bool isSmallerByName(const ExamData& t, const ExamData& other);
	friend bool isBiggerByAge(const ExamData& t, const ExamData& other);
	friend bool isSmallerByAge(const ExamData& t, const ExamData& other);
	friend bool isBiggerBySubject(const ExamData& t, const ExamData& other);
	friend bool isSmallerBySubject(const ExamData& t, const ExamData& other);
	friend bool isBiggerByDate(const ExamData& t, const ExamData& other);
	friend bool isSmallerByDate(const ExamData& t, const ExamData& other);
	friend std::ostream& operator<<(std::ostream& o, const ExamData& data);
	friend std::istream& operator>>(std::istream& i, ExamData& data);
	friend bool operator<=(const ExamData& e1, const ExamData& e2);

private:
	char* name;
	int age;
	char* subject;
	int grade;
	char* date;

	void setData(const ExamData& rhs);
	char* setString(const char* source);

};
#endif