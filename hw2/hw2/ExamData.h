#ifndef _EXAM_DATA_H_
#define _EXAM_DATA_H_
#include <iostream>

class ExamData
{
public:
	ExamData(){};
	ExamData(const char* line);
	ExamData(char* name, int age, char* subject, int grade, char* date);
	ExamData(const ExamData& rhs);
	ExamData& operator=(const ExamData& rhs);
	~ExamData();
	friend bool isBiggerByName(const ExamData& t, const ExamData& other);
	friend bool isSmallerByName(const ExamData& t, const ExamData& other);
	friend bool isBiggerByAge(const ExamData& t, const ExamData& other);
	friend bool isSmallerByAge(const ExamData& t, const ExamData& other);
	friend bool isBiggerBySubject(const ExamData& t, const ExamData& other);
	friend bool isSmallerBySubject(const ExamData& t, const ExamData& other);
	friend bool isBiggerByGrade(const ExamData& t, const ExamData& other);
	friend bool isSmallerByGrade(const ExamData& t, const ExamData& other);
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