#define _CRT_SECURE_NO_WARNINGS
#include"CircleLinkList.h"

typedef struct PERSON
{
	CircleLinkNode node;
	char name[64];
	int age;
	int score;
}Person;

void MyPrint(CircleLinkNode* data)
{
	Person* p = (Person*)data;
	printf("Name:%s Age:%d Score:%d\n", p->name, p->age, p->score);
}

int MyCompare(CircleLinkNode* data1, CircleLinkNode* data2)
{
	Person* p1 = (Person*)data1;
	Person* p2 = (Person*)data2;
	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age && p1->score == p2->score)
	{
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}

int main(void)
{

	CircleLinkList* clist = Init_CircleLinkList();
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");

	p1.age = 10;
	p2.age = 20;
	p3.age = 34;
	p4.age = 23;
	p5.age = 15;

	p1.score = 10;
	p2.score = 23;
	p3.score = 36;
	p4.score = 63;
	p5.score = 95;

	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p1);
	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p2);
	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p3);
	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p4);
	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p5);

	Print_CircleLinkList(clist, MyPrint);
	printf("\n");
	Person pDel;
	strcpy(pDel.name, "ccc");
	pDel.age = 34;
	pDel.score = 36;
	RemoveByValue_CircleLinkList(clist, (CircleLinkNode*)&pDel,MyCompare);
	Print_CircleLinkList(clist, MyPrint);
	FreeeSpace_CircleLinkList(clist);

	system("pause");
	return 0;
}