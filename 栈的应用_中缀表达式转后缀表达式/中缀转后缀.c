#define _CRT_SECURE_NO_WARNINGS

#include"LinkStack.h"


int IsNumber(char c)
{
	return c >= '0' && c <= '9';
}

void NumberOperate(char* p)
{
	printf("%c", *p);
}

int IsLeft(char c)
{
	return c == '(';
}

int IsRight(char c)
{
	return c == ')';
}

int IsOperator( char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int GetPriority(char c)
{
	if (c == '*' || c == '/')
	{
		return 2;
	}
	if (c == '+' || c == '-')
	{
		return 1;
	}
	return 0;
}
typedef struct MYCHAR
{
	LinkNode node;
	char* p;
}MyChar;

MyChar* CreateMychar(char* p)
{
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->p = p;
	return mychar;
}

void LeftOperate(LinkStack* stack, char* p)
{
	Push_LinkStack(stack, (LinkNode*)CreateMychar(p));
}

void RightOperate(LinkStack* stack)
{
	while (Size_LinkStack(stack) > 0)
	{
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		if (IsLeft(*(mychar->p)))
		{
			Pop_LinkStack(stack);
			break;
		}
		printf("%c", *(mychar->p));
		Pop_LinkStack(stack);
		free(mychar);
	}
}

void OperatorOperate(LinkStack* stack, char* p)
{
	MyChar* mychar = (MyChar*)Top_LinkStack(stack);
	if (mychar == NULL)
	{
		Push_LinkStack(stack, (LinkNode*)CreateMychar(p));
		return;
	}
	if (GetPriority(*(mychar->p)) < GetPriority(*p))
	{
		Push_LinkStack(stack, (LinkNode*)CreateMychar(p));
		return;
	}
	else
	{
		while (Size_LinkStack(stack) > 0)
		{
			MyChar* mychar2 = (MyChar*)Top_LinkStack(stack);
			if (GetPriority(*(mychar2->p)) < GetPriority(*p))
			{
				Push_LinkStack(stack, (LinkNode*)CreateMychar(p));
				break;
			}
			printf("%c", *(mychar2->p));
			Pop_LinkStack(stack);
			free(mychar2);
		}
	}
}

int main()
{
	char* str = "8+(3-1)*5";
	char* p = str;
	LinkStack* stack = Init_LinkStack();

	while (*p != '\0')
	{
		if (IsNumber(*p))
		{
			NumberOperate(p);
		}
		if (IsLeft(*p))
		{
			LeftOperate(stack, p);
		}
		if (IsRight(*p))
		{
			RightOperate(stack);

		}
		if (IsOperator(*p))
		{
			OperatorOperate(stack, p);
		}

		p++;
	}
	while (Size_LinkStack(stack) > 0)
	{
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		printf("%c", *(mychar->p));
		Pop_LinkStack(stack);
		free(mychar);
	}
	printf("\n");
	return 0;
}