#define _CRT_SRCURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/timeb.h>

#define MAX 10

long getSystemTime()
{
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void BubbleSort(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		int min = i;
		for (int j = i+1; j < length ; j++)
		{
			if (arr[j ] < arr[min])
			{
				min=j;
			}
		}
		if (min != i)
		{
			Swap(&arr[min], &arr[i]);
		}
	}
}

void PrintArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	printf("排序前：\n");
	PrintArray(arr, MAX);
	long t_start = getSystemTime();
	BubbleSort(arr, MAX);
	long t_end = getSystemTime();
	printf("排序后：\n");
	PrintArray(arr, MAX);
	printf("冒泡时间：%d\n", t_end - t_start);
	return 0;
}