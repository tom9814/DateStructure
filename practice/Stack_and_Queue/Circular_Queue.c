#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAXSIZE 4
typedef int elemtype;
//循环队列结构体定义
typedef struct
{
    elemtype *data;
    int front;
    int rear;
}Queue;

//循环队列初始化
Queue *initqueue()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->data = (elemtype*)malloc(sizeof(elemtype) * MAXSIZE);
    q->front = 0;
    q->rear = 0;
    return q;
}

//入队
int equeue(Queue *q, elemtype e)
{
    if ((q->rear + 1) % MAXSIZE == q->front) //如果front移动了，那么循环队列永远满不了
    {
        printf("满了\n");
        return 0;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;
    return 1;
}

//出队
int dequeue(Queue *q, elemtype *e)
{
    if (q->front == q->rear)
    {
        printf("空队列\n");
        return 0;
    }
    *e = q->data[q->front];
    free(q->data[q->front]);
    q->front = (q->front + 1) % MAXSIZE;
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
    *e = q->data[q->front];
    return 1;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Queue *q = initqueue();
    elemtype e;
    equeue(q,10);
    equeue(q,20);
    equeue(q,30);
    dequeue(q,&e);
    printf("%d\n",e);
    getHead(q,&e);
    printf("%d\n",e);

    system("pause");
    return 0;
}