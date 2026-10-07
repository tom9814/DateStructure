#include <stdio.h>
#include <windows.h>
#define MAXSIZE 5
typedef int elemtype;
//队列的顺序表结构体定义
typedef struct queue
{
    elemtype data[MAXSIZE];
    int front;
    int rear;
}Queue;

//队列初始化
int initQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}

//出队
elemtype dequeue(Queue *q)
{
    if (q->front == q->rear)
    {
        printf("空队列\n");
        return 0;
    }
    elemtype e = q->data[q->front];
    q->front++;
    return e;
}

//判断队列是否真的满了
int fullQueue(Queue *q)
{
    if (q->front > 0)
    {
        int step = q->front;
        //移动数据
        for(int i = q->front; i <= q->rear; i++)
        {
            q->data[i - step] = q->data[i];
        }
        //移动队头和队尾
        q->front = 0;
        q->rear -= step;
        return 1;
    }
    else
    {
        printf("真的满了\n");
        return 0;
    }
}

//入队
int equeue(Queue *q, elemtype e)
{   
    if (q->rear >= MAXSIZE)
    {
        if (!fullQueue(q))
        {
            return 0;
        }  
    }
    q->data[q->rear] = e;
    q->rear++;
    return 1;
}

//获取队头数据
elemtype getHead(Queue *q)
{
    if (q->front == q->rear)
    {
        printf("空队列\n");
        return 0;
    }
    elemtype e = q->data[q->front];
    return e;
}

int main()
{   
    SetConsoleOutputCP(CP_UTF8);
    Queue q;
    initQueue(&q);
    equeue(&q,10);
    equeue(&q,20);
    equeue(&q,30);
    equeue(&q,40);
    equeue(&q,50);
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    printf("%d\n",getHead(&q));
    equeue(&q,30);
    system("pause");
    return 0;
}