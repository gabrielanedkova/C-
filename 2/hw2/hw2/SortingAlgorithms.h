#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H
#include "ExamData.h"

class SortingAlgorithms
{
public:
	static void mergeSort(ExamData arr[], int start, int end, bool(*f)(const ExamData& t, const ExamData& other));
	static void quickSort(ExamData arr[], int start, int end, bool(*f)(const ExamData& t, const ExamData& other));
	static void heapSort(ExamData arr[], int size, bool(*f)(const ExamData& t, const ExamData& other));
	static void countingSort(ExamData arr[], const int size, const char* order);
	static void insertionSort(ExamData arr[], int size, bool(*f)(const ExamData& t, const ExamData& other));

private:
	SortingAlgorithms();
	static void merge(ExamData arr[], int start, int middle, int end, bool(*f)(const ExamData& t, const ExamData& other));
	static int partition(ExamData arr[], int start, int end, bool(*f)(const ExamData& t, const ExamData& other));
	static void heapify(ExamData arr[], int size, int i, bool(*f)(const ExamData& t, const ExamData& other));

};

#endif