#include"SeqStack.h"

SeqStack* Init_SeqStack()
{
	SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
	for (int i = 0; i < MAX_SIZE; i++)
	{
		stack->data[i] = NULL;
	}
	stack->size = 0;
	return stack;
}

void Push_SeqStack(SeqStack* stack, void* data)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->size == MAX_SIZE)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	stack->data[stack->size] = data;
	stack->size++;
}

void* Top_SeqStack(SeqStack* stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	if (stack->size == 0)
	{
		return NULL;
	}

	return stack->data[stack->size - 1];
}

void Pop_SeqStack(SeqStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->size == 0)
	{
		return;
	}
	stack->data[stack->size - 1] = NULL;
	stack->size--;

}

int IsEmpty(SeqStack* stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	if (stack->size == 0)
	{
		return SEQSTACK_TRUE;
	}
	return SEQSTACK_FALSE;

}

int Size_SeqStack(SeqStack* stack)
{
	return stack->size;
}

void Clear_SeqStack(SeqStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	for (int i = 0; i <stack->size; i++)
	{
		stack->data[i] = NULL;
	}
	stack->size = 0;
}

void FreeSpace_SeqStack(SeqStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
}