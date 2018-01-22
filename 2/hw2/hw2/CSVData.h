#ifndef CSV_DATA_H
#define CSV_DATA_h

#include "ExamData.h"
class CSVData
{
public:
	CSVData(const char* argv);
	~CSVData();
	void add(const ExamData newData);
	void print()const;
	ExamData* getData()const { return data;};
	void sortByDate(const char* order);
	void sortByName(const char* order);
	void sortByAge(const char* order);
	void sortByGrade(const char* order);
	void sortBySubject(const char* order);

private:
	ExamData* data;
	int size;
	int capacity;
};

#endif