#include "CSVData.h"
#include "SortingAlgorithms.h"
#include <fstream>
#include <sstream>

int getDataSize(const char* argv);
CSVData::CSVData(const char* argv)
{
	capacity = getDataSize(argv);
	data = new ExamData[capacity];
	char line[1024];
	std::ifstream in(argv);
	if (in.is_open())
	{
		in.getline(line, 1024);
		while (in.getline(line, 1024))
		{
			ExamData newData(line);
			add(newData);
		}
	}
	in.close();
}

CSVData::~CSVData()
{
	delete[] data;
}

void CSVData::add(const ExamData newData)
{
	if (size >= capacity)
		return;
	data[size] = newData;
	++size;
}

void CSVData::print()const
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << data[i];
	}
}

void CSVData::printReversed()const
{
	for (int i = size-1; i >= 0; --i)
	{
		std::cout << data[i];
	}
}

void CSVData::sortByDate(const char* order)
{
	if (strcmp(order, "asc") == 0)
		SortingAlgorithms::mergeSort(data, 0, size - 1, isSmallerByDate);
	else if (strcmp(order, "desc") == 0)
		SortingAlgorithms::mergeSort(data, 0, size - 1, isBiggerByDate);

}

void CSVData::sortByName(const char* order)
{
	if (strcmp(order, "asc") == 0)
		SortingAlgorithms::quickSort(data, 0, size - 1, isSmallerByName);
	else if (strcmp(order, "desc") == 0)
		SortingAlgorithms::quickSort(data, 0, size - 1, isBiggerByName);
}

void CSVData::sortByAge(const char* order)
{
	if (strcmp(order, "asc") == 0)
		SortingAlgorithms::quickSort(data, 0, size - 1, isSmallerByAge);
	else if (strcmp(order, "desc") == 0)
		SortingAlgorithms::quickSort(data, 0, size - 1, isBiggerByAge);
}

int getDataSize(const char* fileName)
{
	int cnt = -1;
	char line[1024];
	std::ifstream in(fileName);
	while (in.getline(line, 1024))
	{
		++cnt;
	}
	return cnt;
	in.close();
}

