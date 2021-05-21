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
void ShellSort(int arr[], int length)
{
	int incresement = length;
	int i, j, k;
	do
	{
		incresement = incresement / 3 + 1;
		for (i = 0; i < incresement; i++)
		{
			for (j = i + incresement; j < length; j += incresement)
			{
				if (arr[j] < arr[j - incresement])
				{
					int temp = arr[j];
					for (k = j - incresement; k >= 0 && temp < arr[k]; k -= incresement)
					{
						arr[k + incresement] = arr[k];
					}
					arr[k + incresement] = temp;
				}
			}
		}
		

	} while (incresement > 1);
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
	printf("ÅÅÐòÇ°£º\n");
	PrintArray(arr, MAX);
	ShellSort(arr, MAX);
	printf("ÅÅÐòºó£º\n");
	PrintArray(arr, MAX);

	return 0;
}