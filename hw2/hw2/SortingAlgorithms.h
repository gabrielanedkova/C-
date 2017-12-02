#include "ExamData.h"

class SortingAlgorithms
{
public:
	static void mergeSort(ExamData arr[], int start, int end, bool(*f)(const ExamData& t, const ExamData& other));
	static void quickSort(ExamData arr[], int start, int end, bool(*f)(const ExamData& t, const ExamData& other));

private:
	SortingAlgorithms();
	static void merge(ExamData arr[], int start, int middle, int end, bool(*f)(const ExamData& t, const ExamData& other));
	static int partition(ExamData arr[], int start, int end, bool(*f)(const ExamData& t, const ExamData& other));

};