#ifndef CIRCLELINKLIST
#define CIRCLELINKLIST

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct CIRCLELINKNODE
{
	struct CIRCLELINKNODE* next;
	
}CircleLinkNode;

typedef struct CIRCLELINKLIST
{
	CircleLinkNode head;
	int size;
}CircleLinkList;

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0

typedef int(*COMPARENODE) (CircleLinkNode*, CircleLinkNode*);

typedef void(*PRINTNODE)(CircleLinkNode*);

CircleLinkList* Init_CircleLinkList();

void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data);

CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist);

void RemoveBypos_CircleLinList(CircleLinkList* clist, int pos);

void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);

int Size_CircleLinkList(CircleLinkList* clist);

int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data,COMPARENODE compare);

int IsEmpty_CicleLinkList(CircleLinkList* clist);

void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print);

void FreeeSpace_CircleLinkList(CircleLinkList* clist);

#endif // !CIRCLELINLIST
