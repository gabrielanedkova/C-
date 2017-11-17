#include "Student.h"
#include <iostream>
bool Student::changeGrade(float newGrade){
	if (newGrade >= 2 && newGrade <= 6){
		this->grade = newGrade;
		return true;
	}
	return false;
}
bool Student::setName(char* name){
	size_t len = strlen(name);
	if (name != nullptr && name != ""){
		this->name = new (std::nothrow)char[len + 1];
		if (!this->name)
			return false;

		strcpy_s(this->name, len + 1, name);
		return true;
	}
	return false;
}

bool  Student::setFn(short fn){
	if (fn >= 42900 && fn <= 45150){
		this->fn = fn;
		return true;
	}
	return false;
}

bool Student::setGrade(float grade){
	if (grade >= 2 &&  grade <=6){
		this->grade = grade;
		return true;
	}
	return false;
}

char* Student::getName(){
	return this->name;
}
int Student::getFn(){
	return this->fn;
}

float Student::getGrade(){
	return this->grade;
}