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

void SortingAlgorithms::countingSort(ExamData arr[], const int size, const char* order)
{
	int grades[] = { 0, 0, 0, 0, 0};
	for (int i = 0; i < size; ++i)
	{
		++grades[arr[i].getGrade() - 2];
	}
	for (int i = 1; i < 5; ++i)
	{
		grades[i] += grades[i - 1];
	}
	ExamData* temp = new ExamData[size];
	for (int i = size - 1; i >= 0; --i)
	{
		int grade = arr[i].getGrade();
		temp[grades[grade - 2] - 1] = arr[i];
		--grades[grade - 2];

	}
	if (strcmp(order, "asc") == 0)
	{
		for (int i = 0; i < size; ++i)
		{
			arr[i] = temp[i];
		}
	}
	else if (strcmp(order, "desc") == 0)
	{
		int last = size - 1;
		for (int i = 0; i < size; ++i)
		{
			arr[i] = temp[last];
			--last;
		}
	}
	delete[] temp;
}
void SortingAlgorithms::heapify(ExamData arr[], int size, int i, bool(*f)(const ExamData& t, const ExamData& other))
{
	int largest = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
	if (leftChild<size && (*f)(arr[leftChild],arr[largest]))
	{
		largest = leftChild;
	}
	if (rightChild<size && (*f)(arr[rightChild], arr[largest]))
	{
		largest = rightChild;
	}
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, size, largest, (*f));
	}
}

void SortingAlgorithms::heapSort(ExamData arr[], int size, bool(*f)(const ExamData& t, const ExamData& other))
{
	for (int i = size / 2 - 1; i >= 0; --i)
		heapify(arr, size, i, (*f));
	for (int i = size - 1; i >= 0; --i)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0, (*f));
	}
}

void SortingAlgorithms::insertionSort(ExamData arr[], int size, bool(*f)(const ExamData& t, const ExamData& other))
{
	ExamData key;
	for (int i = 1; i < size; ++i)
	{
		key = arr[i];
		int j = i - 1;
		while (j >= 0 && (*f)(key, arr[j]))
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void swap( ExamData& e1,  ExamData& e2)
{
	ExamData temp = e1;
	e1 = e2;
	e2 = temp;
}
