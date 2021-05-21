#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct DYNAMICARRAY
{
	int* pAddr;
	int size;
	int capacity;

}Dynamic_Array;

Dynamic_Array* Init_Array();

void PushBack_Array(Dynamic_Array* arr, int value);

void RemoveByPos_Array(Dynamic_Array* arr, int pos);

void RemoveByValue_Array(Dynamic_Array* arr, int value);

int Find_Array(Dynamic_Array* arr, int value);

void Print_Array(Dynamic_Array* arr);

void FreeSpace_Array(Dynamic_Array* arr);

void Clean_Array(Dynamic_Array* arr);

int Capacity_Array(Dynamic_Array* arr);

int Size_Array(Dynamic_Array* arr);

int At_Array(Dynamic_Array* arr);














#endif