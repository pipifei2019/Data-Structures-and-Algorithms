#include"LinkList.h"



LinkList* Init_LinkList()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	return list;

}

void Insert_LinkList(LinkList* list, int pos, LinkNode* data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (pos<0||pos>list->size)
	{
		pos=list->size;
	}

	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	data->next = pCurrent->next;
	pCurrent->next = data;

	list->size++;
}

void Remove_LinkList(LinkList* list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	
	if (pos<0 || pos>list->size)
	{
		return;
	}
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	pCurrent->next = pCurrent->next->next;
	list->size--;


}

int Find_LinkList(LinkList* list, LinkNode* data,COMPARENODE compare)
{
	if (list == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -1;
	}
	
	int index = 0;
	int flag = -1;
	LinkNode* pCurrent = list->head.next;
	while (pCurrent != NULL)
	{
		if (compare(pCurrent, data) == 0)
		{
			flag = index;
			break;
		}
		pCurrent = pCurrent->next;
		index++;
	}
	return flag;
}

int Size_LinkList(LinkList* list)
{

}

void Print_LinkList(LinkList* list, PRINTNODE print)
{
	if (list == NULL)
	{
		return;
	}
	LinkNode* pCurrent = list->head.next;
	while (pCurrent != NULL)
	{
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
}

void FreeSpace_LinkList(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	free(list);
}
