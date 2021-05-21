#include"LinkStack.h"

int IsNumber(char c)
{
	return c >= '0' && c <= '9';
}

typedef struct MYNUM
{
	LinkNode node;
	int val;
}MyNum;

int Calculate(int left, int right, char c)
{
	switch (c)
	{
	case '+':
		return left + right;
		break;
	case '-':
		return left - right;
		break;
	case '*':
		return left * right;
		break;
	case '/':
		return left / right;
		break;
	default:
		break;
	}
}

int main()
{
	char* str = "831-5*+";
	LinkStack* stack = Init_LinkStack();
	char* p = str;
	while (*p != '\0')
	{
		if (IsNumber(*p))
		{
			MyNum* num = (MyNum*)malloc(sizeof(MyNum));
			num->val = *p - '0';
			Push_LinkStack(stack, (LinkNode*)num);
		}
		else
		{
			int  rightnum = ((MyNum*)Top_LinkStack(stack))->val;
			Pop_LinkStack(stack);
			int  lefttnum = ((MyNum*)Top_LinkStack(stack))->val;
			Pop_LinkStack(stack);
			int ret = Calculate(lefttnum, rightnum, *p);
			MyNum* mynum = (MyNum*)malloc(sizeof(MyNum));
			mynum->val = ret;
			Push_LinkStack(stack,(LinkNode*)mynum);
		}

		p++;
	}
	MyNum* result = (MyNum*)Top_LinkStack(stack);
	printf("%d", result->val);
	free(result);
	FreeSpace_LinkStack(stack);
	return 0;
}