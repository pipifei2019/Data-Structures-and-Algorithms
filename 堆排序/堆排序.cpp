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

void MySwap(int arr[], int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void HeapAdjust(int arr[], int index, int len)
{
	int max = index;
	int lchild = index * 2 + 1;
	int rchild = index * 2 + 2;
	if (lchild<len && arr[lchild]>arr[max])
	{
		max = lchild;
	}
	if (rchild<len && arr[rchild]>arr[max])
	{
		max = rchild;
	}

	if (max != index)
	{
		MySwap(arr, max, index);
		HeapAdjust(arr, max, len);
	}

}

void HeapSort(int arr[], int len)
{
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(arr, i, len);
	}
	for (int i = len - 1; i >= 0; i--)
	{
		cout << i << endl;
		MySwap(arr, 0, i);
		HeapAdjust(arr, 0, i);
	}
}

int main()
{
	int myArr[] = {4,2,8,0,5,7,1,3,9};
	int len = sizeof(myArr) / sizeof(int);
	PrintArray(myArr, len);
	HeapSort(myArr, len);
	PrintArray(myArr, len);


	return 0;
}