#include <fstream>
#include "CSVData.h"

void sortData(CSVData& data, const char* column, const char* order)
{
	if (strcmp(column, "name") == 0)
	{
		data.sortByName(order);
	}
	else if (strcmp(column, "age") == 0)
	{
		data.sortByAge(order);
	}
	else if (strcmp(column, "subject") == 0)
	{
		//data.sortBySubject(order);

	}
	else if (strcmp(column, "grade") == 0)
	{
		//data.sortByGrade(order);

	}
	else if (strcmp(column, "date") == 0)
	{
		data.sortByDate(order);
	}
}


int main(int argc, char** argv)
{
	CSVData data(argv[1]);
	data.print();
	std::cout << std::endl;
	sortData(data, argv[2], argv[3]);
	data.print();
	std::cout << std::endl;
	std::cout << &argv[1] << std::endl;
	system("pause");
}