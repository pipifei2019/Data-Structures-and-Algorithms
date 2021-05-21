#ifndef SEQQUEUE_H
#define SEQQUEUE_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 1024

typedef struct SEQQUEUE
{
	void* data[MAX_SIZE];
	int size;
}SeqQueue;


SeqQueue* Init_SeqQueue();

void Push_SeqQueue(SeqQueue* queue, void* data);

void* Front_SeqQueue(SeqQueue* queue);

void Pop_SeqQueue(SeqQueue* queue);

void* Back_SeqQueue(SeqQueue* queue);

int Size_SeqQueue(SeqQueue* queue);

void Clear_SeqQueue(SeqQueue* queue);

void FreeSpace_SeqQueue(SeqQueue* queue);









#endif