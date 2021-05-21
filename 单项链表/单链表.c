#include"LinkList.h"

typedef struct PERSON
{
	char name[64];
	int age;
	int score;

}Person;

void MyPrint(void* data)
{
	Person* p = (Person*)data;
	printf("Name:%s Age:%d Score:%d\n", p->name, p->age, p->score);
}
int main(void)
{
	LinkList* list = Init_LinkList();

	Person p1 = { "aaa",15,68 };
	Person p2 = { "bbb",16,66 };
	Person p3 = { "ccc",15,88 };
	Person p4 = { "ddd",13,62 };
	Person p5 = { "eee",13,18 };
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	Print_LinkList(list, MyPrint);
	printf("\n");
	RemoveByPos_LinkList(list, 3);
	Print_LinkList(list, MyPrint);
	Person* ret = (Person*)Front_LinkList(list);
	printf("Name:%s Age:%d Score:%d\n", ret->name, ret->age, ret->score);

	Free_LinkList(list);
	system("pause");
	return 0;
}