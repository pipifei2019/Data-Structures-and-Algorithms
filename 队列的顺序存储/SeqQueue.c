#include"SeqQueue.h"

//��ʼ��
SeqQueue* Init_SeqQueue() {
    SeqQueue* queue = (SeqQueue*)malloc(sizeof(SeqQueue));
    for (int i = 0; i < MAX_SIZE; i++) {
        queue->data[i] = NULL;
    }
    queue->size = 0;
    return queue;
}
//���
void Push_SeqQueue(SeqQueue* queue, void* data) {

    //������ߵ�����ͷ
    if (queue == NULL) {
        return;
    }
    if (data == NULL) {
        return;
    }

    if (queue->size == MAX_SIZE) {
        return;
    }

    queue->data[queue->size] = data;
    queue->size++;

}
//���ض�ͷԪ��
void* Front_SeqQueue(SeqQueue* queue) {

    if (queue == NULL) {
        return NULL;
    }
    if (queue->size == 0) {
        return NULL;
    }
    return queue->data[0];
}
//����
void Pop_SeqQueue(SeqQueue* queue) {

    //��Ҫ�ƶ�Ԫ��
    if (queue == NULL) {
        return;
    }
    if (queue->size == 0) {
        return;
    }

    for (int i = 0; i < queue->size - 1; i++) {
        queue->data[i] = queue->data[i + 1];
    }
    queue->size--;
}
//���ض�βԪ��
void* Back_SeqQueue(SeqQueue* queue) {
    if (queue == NULL) {
        return NULL;
    }
    if (queue->size == 0) {
        return NULL;
    }

    return queue->data[queue->size - 1];

}
//���ش�С
int Size_SeqQueue(SeqQueue* queue) {
    if (queue == NULL) {
        return -1;
    }

    return queue->size;
}
//��ն���
void Clear_SeqQueue(SeqQueue* queue) {
    if (queue == NULL) {
        return;
    }

    queue->size = 0;

}
//����
void FreeSpace_SeqQueue(SeqQueue* queue) {
    if (queue == NULL) {
        return;
    }

    free(queue);

}