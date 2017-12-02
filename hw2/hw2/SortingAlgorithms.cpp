#include "SortingAlgorithms.h"

void swap(ExamData& e1, ExamData& e2);

void SortingAlgorithms::merge(ExamData arr[], int begin, int middle, int end, bool(*f)(const ExamData& t, const ExamData& other))
{
	int leftSize = middle - begin + 1;
	int rightSize = end - middle;
	ExamData* left = new ExamData[leftSize];
	ExamData* right = new ExamData[rightSize];

	for (int i = 0; i < leftSize; ++i)
		left[i] = arr[begin + i];
	for (int i = 0; i < rightSize; ++i)
		right[i] = arr[middle + i + 1];

	int leftPos = 0;
	int rightPos = 0;
	int pos = begin;
	while (leftPos < leftSize && rightPos < rightSize)
	{
		if ((*f)(left[leftPos], right[rightPos]))
		{
			arr[pos] = left[leftPos];
			++leftPos;
		}
		else
		{
			arr[pos] = right[rightPos];
			++rightPos;
		}
		++pos;
	}

	while (leftPos < leftSize)
	{
		arr[pos] = left[leftPos];
		++pos;
		++leftPos;
	}

	while (rightPos < rightSize)
	{
		arr[pos] = right[rightPos];
		++pos;
		++rightPos;
	}

	delete[] left;
	delete[] right;

}

void SortingAlgorithms::mergeSort(ExamData arr[], int begin, int end, bool(*f)(const ExamData& t, const ExamData& other))
{
	if (begin < end)
	{
		int middle = (begin + end) / 2;
		mergeSort(arr, begin, middle, (*f));
		mergeSort(arr, middle + 1, end, (*f));
		merge(arr, begin, middle, end, (*f));

	}
}

int SortingAlgorithms::partition(ExamData arr[], int start, int end, bool(*f)(const ExamData& t, const ExamData& other))
{
	int middleIndex = start + (end - start) / 2;
	ExamData pivot = arr[middleIndex];
	swap(arr[middleIndex], arr[end]);
	int partitionIndex = start;
	for (int i = start; i < end; ++i)
	{
		if ((*f)(arr[i], pivot))
		{
			swap(arr[i], arr[partitionIndex]);
			++partitionIndex;
		}
	}
	swap(arr[partitionIndex], arr[end]);
	return partitionIndex;
}

void SortingAlgorithms::quickSort(ExamData arr[], int start, int end, bool(*f)(const ExamData& t, const ExamData& other))
{
	if (start < end)
	{
		int partitioningIndex = partition(arr, start, end, (*f));

		quickSort(arr, start, partitioningIndex - 1, (*f));
		quickSort(arr, partitioningIndex + 1, end, (*f));
	}
}

void swap( ExamData& e1,  ExamData& e2)
{
	ExamData temp = e1;
	e1 = e2;
	e2 = temp;
}