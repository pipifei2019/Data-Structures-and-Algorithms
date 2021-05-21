// 栈容器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include"SeqStack.h"

typedef struct PERSON
{
    char name[64];
    int age;
}Person;

int main()
{
    //printf("hello world");
    SeqStack* stack = Init_SeqStack();
    Person p1 = { "aaa",10 };
    Person p2 = { "bbb",20 };
    Person p3 = { "ccc",30 };
    Person p4 = { "ddd",40 };
    Person p5 = { "eee",50 };
    Push_SeqStack(stack, &p1);
    Push_SeqStack(stack, &p2);
    Push_SeqStack(stack, &p3);
    Push_SeqStack(stack, &p4);
    Push_SeqStack(stack, &p5);

    while (Size_SeqStack(stack) > 0)
    {
        Person* person = (Person*)Top_SeqStack(stack);
        printf("Name:%s Age:%d\n", person->name, person->age);
        Pop_SeqStack(stack);
    }
    FreeSpace_SeqStack(stack);

    system("pause");
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
