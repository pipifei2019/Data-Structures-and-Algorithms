#define _CRT_SRCURE_NO_WARNING
#include<iostream>
using namespace std;
#include<time.h>
#include<sys/timeb.h>

#define MAX 10

int* CreateArray()
{
	srand((unsigned int)time(NULL));
	int* arr = (int*)malloc(sizeof(int) * MAX);
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	return arr;
}

void PrintArray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void Merge(int arr[], int start, int end, int mid, int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;

	int length = 0;

	while (i_start <=i_end && j_start <=j_end)
	{
		if (arr[i_start] < arr[j_start])
		{
			temp[length] = arr[i_start];
			i_start++;
			length++;
		}
		else
		{
			temp[length] = arr[j_start];
			j_start++;
			length++;
		}
	}
	while (i_start <= i_end)
	{
		temp[length] = arr[i_start];
		i_start++;
		length++;
	}
	while (j_start <= j_end)
	{
		temp[length] = arr[j_start];
		j_start++;
		length++;
	}
	for (int i = 0; i < length; i++)
	{
		arr[start + i] = temp[i];
	}
}
void MergeSort(int arr[], int start, int end, int* temp)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	MergeSort(arr, start, mid, temp);
	MergeSort(arr, mid + 1, end, temp);
	Merge(arr, start, end, mid, temp);
}

int main()
{
	int *myArr = CreateArray();
	PrintArray(myArr, MAX);
	int * temp = (int*)malloc(sizeof(int)*MAX);
	MergeSort(myArr, 0, MAX-1 ,temp);
	PrintArray(myArr, MAX);


	free(temp);
	free(myArr);
	

	return 0;
}