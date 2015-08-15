// 快速排序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int quick_partition(int* array, int begin_index, int end_index)
{
	int pivot_index;
	int pivot = array[end_index];
	int low_index = begin_index - 1;
	int high_index = begin_index;
	for (; high_index <= end_index-1;high_index++)
	{
		if (array[high_index] <= pivot)
		{
			low_index++;
			swap(array[high_index], array[low_index]);
		}
	}
	pivot_index = low_index + 1;
	swap(array[pivot_index], array[end_index]);

	return  pivot_index;
}
void quick_sort(int* array, int begin_index, int end_index)
{
	if (begin_index < end_index)
	{
		int pivot_index = quick_partition(array, begin_index, end_index);
		quick_sort(array, begin_index, pivot_index - 1);
		quick_sort(array, pivot_index + 1, end_index);
	}
}
void print_array(int* array, int begin_index, int end_index)
{
	for (int i = begin_index; i <= end_index;i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int array[] = { 5, 6, 9, 0, 6, 9, 6, 4, 8, 2, 47, 2, 66, 5, 4, 1, 3, 3, 4, 2, 3,95959,-1,-99,0x0025 };

	cout << "排序前的数组：";
	print_array(array, 0, sizeof(array) / sizeof(int) - 1);
	
	quick_sort(array, 0, sizeof(array) / sizeof(int) - 1);

	cout << "排序后的数组：";
	print_array(array, 0, sizeof(array) / sizeof(int) - 1);

	
	system("pause");

	return 0;
}

