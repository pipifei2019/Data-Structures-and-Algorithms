#ifndef LINKSTACK_H
#define LINKSTACK_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LINKNODE
{
	struct LINKNODE* next;

}LinkNode;

typedef struct LINKSTACK
{
	LinkNode head;
	int size;
}LinkStack;

LinkStack* Init_LinkStack();

void Push_LinkStack(LinkStack* stack, LinkNode* data);

void Pop_LinkStack(LinkStack* stack);

LinkNode* Top_LinkStack(LinkStack* stack);

int Size_LinkStack(LinkStack* stack);

void Clear_LinkStack(LinkStack* stack);

void FreeSpace_LinkStack(LinkStack* stack);




































#endif