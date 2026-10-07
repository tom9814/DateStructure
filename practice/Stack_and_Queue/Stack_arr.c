#include <stdio.h>
#include <windows.h>
#define MAXSIZE 100
typedef int elemtype;

//栈的顺序表定义
typedef struct stack 
{
    elemtype data[MAXSIZE];
    int top;
}Stack;

//栈的初始化
int initstack(Stack *s)
{
    s->top = -1;
    return 1;
}

//压栈
int push(Stack *s, elemtype data)
{
    if(s->top == MAXSIZE - 1)
    {
        printf("栈满了\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = data;
    return 1;
}

//出栈
int pop(Stack *s, elemtype *e)
{
    if (s->top == -1)
    {
        printf("空栈\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}

//获取栈顶元素
int getTop(Stack *s, elemtype *e)
{
    if (s->top == -1)
    {
        printf("空栈\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}


int main()
{
    Stack s;
    initstack(&s);
    push(&s,10);
    push(&s,20);
    push(&s,30);
    elemtype e;
    pop(&s,&e);
    printf("%d\n",e);
    getTop(&s,&e);
    printf("%d\n",e);

    system("pause");
    return 0;
}