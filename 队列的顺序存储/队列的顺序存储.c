#include"SeqQueue.h"
#define _CTR_SECURE_NO_WARNINGS

typedef struct PERSON
{
	char name[64];
	int age;
}Person;

int main()
{
	SeqQueue* queue = Init_SeqQueue();
	printf("%d", queue->size);
	Person p1 = { "aaa",10 };
	Person p2 = { "bbb",20 };
	Person p3 = { "ccc",30 };
	Person p4 = { "ddd",40 };
	Person p5 = { "eee",50 };
	
	Push_SeqQueue(queue, &p1);
	Push_SeqQueue(queue, &p2);
	Push_SeqQueue(queue, &p3);
	Push_SeqQueue(queue, &p4);
	Push_SeqQueue(queue, &p5);
	Person* backPerson = (Person*)Back_SeqQueue(queue);
	printf("¶ÓÎ²ÔªËØ:Name:%s  Age:%d\n", backPerson->name, backPerson->age);
	while (Size_SeqQueue(queue) > 0)
	{
		Person* person = (Person*)Front_SeqQueue(queue);
		printf("Name:%s Age:%d\n", person->name, person->age);
		Pop_SeqQueue(queue);
	}
	FreeSpace_SeqQueue(queue);


	system("pause");
	return 0;
}
