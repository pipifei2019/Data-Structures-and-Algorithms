#define _CRT_SRCURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/timeb.h>

#define MAX 10000

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
		for (int j = i; j < length - i - 1; j++)
		{
			if (arr[j+1] <= arr[j])
			{
				Swap(&arr[j+1], &arr[j]);
			}
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
	printf("????ǰ??\n");
	PrintArray(arr, MAX);
	long t_start = getSystemTime();
	BubbleSort(arr, MAX);
	long t_end = getSystemTime();
	printf("????????\n");
	PrintArray(arr, MAX);
	printf("ð??ʱ?䣺%d\n", t_end - t_start);
	return 0;
}