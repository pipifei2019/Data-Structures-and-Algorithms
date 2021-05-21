#define _CRT_SRCURE_NO_WARNING
#include<iostream>
using namespace std;

void PrintArray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void QuickSort(int arr[], int start, int end)
{
	int i = start;
	int j = end;
	int temp = arr[start];
	if (i < j)
	{
		while (i < j)
		{
			while (i < j && arr[j] >= temp)
			{
				j--;
			}
			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}
			while (i < j && arr[i] < temp)
			{
				i++;
			}
			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}
		}
		arr[i] = temp;
		QuickSort(arr, start, i - 1);
		QuickSort(arr, i + 1, end);
	}
}

int main()
{
	int myArr[] = { 4,2,8,0,5,7,1,3,9 };
	
	int len = sizeof(myArr) / sizeof(myArr[0]);
	PrintArray(myArr, len);
	QuickSort(myArr, 0, len - 1);
	PrintArray(myArr, len);
	
	return 0;
}