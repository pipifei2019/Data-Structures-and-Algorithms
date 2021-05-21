#include"LinkStack.h"

//��ʼ������

LinkStack* Init_LinkStack() {

    LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));

    stack->head.next = NULL;

    stack->size = 0;



    return stack;

}

//��ջ

void Push_LinkStack(LinkStack* stack, LinkNode* data) {

    if (stack == NULL) {

        return;

    }



    if (data == NULL) {

        return;

    }



    data->next = stack->head.next;

    stack->head.next = data;

    stack->size++;

}

//��ջ

void Pop_LinkStack(LinkStack* stack) {

    if (stack == NULL) {

        return;

    }



    if (stack->size == 0) {

        return;

    }



    //��һ����Ч���

    LinkNode* pNext = stack->head.next;

    stack->head.next = pNext->next;



    stack->size--;

}

//����ջ��Ԫ��

LinkNode* Top_LinkStack(LinkStack* stack) {

    if (stack == NULL) {

        return NULL;

    }

    if (stack->size == 0) {

        return NULL;

    }

    return stack->head.next;

}

//����ջԪ�صĸ���

int Size_LinkStack(LinkStack* stack) {

    if (stack == NULL) {

        return -1;

    }

    return stack->size;

}

//���ջ

void Clear_LinkStack(LinkStack* stack) {

    if (stack == NULL) {

        return;

    }

    stack->head.next = NULL;

    stack->size = 0;

}

//����ջ

void FreeSpace_LinkStack(LinkStack* stack) {

    if (stack == NULL) {

        return;

    }

    free(stack);

}