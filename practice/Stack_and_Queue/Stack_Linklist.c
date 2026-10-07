#include <stdio.h>
#include <windows.h>
typedef int elemtype;
//栈的链表结构体定义
typedef struct stack
{
    elemtype data;
    struct stack *next;
}Stack;

//栈的初始化
Stack *initStack()
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = 0;
    s->next = NULL;
    return s;
}

//压栈
int push(Stack *s, elemtype e)
{
    Stack *p = (Stack*)malloc(sizeof(Stack));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1;
}

//出栈
int pop(Stack *s, elemtype *e)
{
    if (s->next == NULL)
    {
        printf("空栈\n");
        return 0;
    }
    Stack *p = s->next;
    *e = p->data;
    s->next = p->next;
    free(p);
    return 1;
}

//获取栈顶元素
int getTop(Stack *s, elemtype *e)
{
    if (s->next == NULL)
    {
        printf("空栈\n");
        return 0;
    }
    *e = s->next->data;
    return 1;
}

int main()
{
    Stack *s = initStack();
    push(s,10);
    push(s,20);
    push(s,30);
    elemtype e;
    pop(s,&e);
    printf("%d\n",e);
    getTop(s,&e);
    printf("%d\n",e);

    system("pause");
    return 0;
}