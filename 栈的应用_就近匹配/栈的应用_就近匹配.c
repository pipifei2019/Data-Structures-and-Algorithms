#define _CRT_SECURE_NO_WARNINGS

#include"LinkStack.h"

typedef struct MYCHAR
{
	LinkNode node;
	char* pAddress;
	int index;
}MyChar;

int IsLeft(char c)
{
	return c == '(';
}

int IsRight(char c)
{
	return c == ')';
}

MyChar* CreateMyChar(char* p,int index)
{
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->pAddress = p;
	mychar->index = index;
	return mychar;
}

void ShowError(char* str, int pos)
{
	printf("%s\n", str);
	for (int i = 0; i < pos; i++)
	{
		printf(" ");
	}
	printf("A\n");
}
int main()
{
	char* str = "1+2+6((dsf)dsflp((sdfs)";

	LinkStack* stack = Init_LinkStack();

	char* p = str;
	int index = 0;
	
	while (*p != '\0')
	{
		if (IsLeft(*p))
		{
			Push_LinkStack(stack,(LinkNode*)CreateMyChar(p,index));
		}
		if (IsRight(*p))
		{
			if (Size_LinkStack(stack) > 0)
			{
				MyChar* mychar = (MyChar*)Top_LinkStack(stack);
				if (IsLeft(*(mychar->pAddress)))
				{
					Pop_LinkStack(stack);
					free(mychar);
				}
			}
			else
			{
				printf("ÓÒÀ¨ºÅÃ»ÓÐÆ¥Åä×óÀ¨ºÅ£¡\n");
				ShowError(str, index);
				break;
			}
		}
		p++;
		index++;
	}

	while (Size_LinkStack(stack) > 0)
	{
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		printf("×óÀ¨ºÅÃ»ÓÐÆ¥ÅäµÄÓÒÀ¨ºÅ£¡\n");
		ShowError(str, mychar->index);
		Pop_LinkStack(stack);
		free(mychar);
	}



	printf("hello world\n");
	return 0;
} 