#ifndef SEQSTACK_H
#define SEQSTACK_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1024
#define SEQSTACK_TRUE 1
#define SEQSTACK_FALSE 0
typedef struct SEQSTACK
{
	void* data[MAX_SIZE];
	int size;
}SeqStack;

SeqStack* Init_SeqStack();

void Push_SeqStack(SeqStack* stack, void*data);

void* Top_SeqStack(SeqStack* stack);

void Pop_SeqStack(SeqStack* stack);

int IsEmpty(SeqStack* stack);

int Size_SeqStack(SeqStack* stack);

void Clear_SeqStack();

void FreeSpace_SeqStack(SeqStack* stack);





#endif