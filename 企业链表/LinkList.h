#ifndef LINKLIST_H
#define LINKLIST_H


#include<stdlib.h>
#include<stdio.h>
typedef struct LINKNODE
{
	struct LINKNODE* next;
}LinkNode;

typedef struct LINKLIST
{
	LinkNode head ;
	int size;
}LinkList;

typedef void(*PRINTNODE)(LinkNode*);

typedef int(*COMPARENODE)(LinkNode*, LinkNode*);

LinkList* Init_LinkList();

void Insert_LinkList(LinkList* list, int pos,LinkNode*data);

void Remove_LinkList(LinkList* list, int pos);

int Find_LinkList(LinkList* list, LinkNode* data,COMPARENODE compare);

int Size_LinkList(LinkList* list);

void Print_LinkList(LinkList* list, PRINTNODE print);

void FreeSpace_LinkList(LinkList* list);








#endif // !LINKLIST_H
