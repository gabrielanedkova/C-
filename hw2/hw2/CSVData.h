#include "ExamData.h"
class CSVData
{
public:
	CSVData(const char* argv);
	~CSVData();
	void add(const ExamData newData);
	void print()const;
	void printReversed()const;
	ExamData* getData(){ return data; };
	void sortByDate(const char* order);
	void sortByName(const char* order);
	void sortByAge(const char* order);

private:
	ExamData* data;
	int size;
	int capacity;
};