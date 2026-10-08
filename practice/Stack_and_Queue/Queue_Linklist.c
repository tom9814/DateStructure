#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef int elemtype;
//队列的链表结构定义
typedef struct queueNode
{
    elemtype data;
    struct queueNode *next;
}QueueNode;

typedef struct
{
    QueueNode *front;
    QueueNode *rear;
}Queue;

//队列的初始化
Queue *initQueue()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = 0;
    node->next = NULL;
    q->front = node;
    q->rear = node;
    return q;
}

//入队
void equeue(Queue *q, elemtype e)
{
    QueueNode *newnode = (QueueNode*)malloc(sizeof(QueueNode));
    newnode->data = e;
    newnode->next = NULL;
    q->rear->next = newnode;
    q->rear = newnode;
}

//出队
int dequeue(Queue *q, elemtype *e)
{
    if (q->front == q->rear)
    {
        printf("空表\n");
        return 0;
    }
    QueueNode *node = q->front->next;
    *e = node->data;
    q->front->next = node->next;
    if (q->rear == node)
    {
        q->front = q->rear;
    }
    free(node);
    return 1;
}

//获取队头元素
int getHead(Queue *q, elemtype *e)
{
    if (q->front == q->rear)
    {
        printf("空表\n");
        return 0;
    }
    *e = q->front->next->data;
    return 1;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Queue *q = initQueue();
    equeue(q,10);
    equeue(q,20);
    equeue(q,30);
    equeue(q,40);
    elemtype e = 0;
    dequeue(q,&e);
    printf("%d\n",e);
    dequeue(q,&e);
    printf("%d\n",e);
    getHead(q,&e);
    printf("%d\n",e);

    system("pause");
    return 0;
}