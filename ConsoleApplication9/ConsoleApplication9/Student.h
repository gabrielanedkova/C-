#ifndef STUDENT_H
#define STUDENT_H

class Student{
	char* name;
	short fn;
	float grade;
public:
	bool changeGrade(float newGrade);
	bool setName(char* name);
	bool setFn(short fn);
	bool setGrade(float grade);
	char* getName();
	int getFn();
	float getGrade();
};
#endif