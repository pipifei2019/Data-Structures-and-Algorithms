#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"DynamicArray.h"

void test01()
{
	Dynamic_Array* myArray = Init_Array();
	for (int i = 0; i < 10; i++)
	{
		PushBack_Array(myArray, i);
	}
	Print_Array(myArray);
	//FreeSpace_Array(myArray);
	RemoveByPos_Array(myArray, 0);
	RemoveByValue_Array(myArray, 7);
	Print_Array(myArray);
	int pos = Find_Array(myArray, 5);
	printf("5²éÕÒµ½£ºpos%d %d\n",pos, At_Array(myArray, pos));
}

int main(void)
{
	test01();

	system("pause");
	return 0;
}