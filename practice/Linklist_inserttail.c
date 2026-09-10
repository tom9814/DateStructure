#include <stdio.h>
#include <stdlib.h>
typedef int elemtype;
typedef struct node
{
    elemtype date;
    struct node *next;
} Node;
// 链表初始化
Node *initlist()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->date = 0;
    head->next = NULL;
    return head;
}
// 链表尾插法插入数据,先写找尾节点的函数
Node *get_tail(Node *L)
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}
Node *insertelem(Node *tail, elemtype e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->date = e;
    tail->next = p;
    p->next = NULL;
    return p;
}
// 链表遍历
void listNode(Node *L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d\n", p->date);
        p = p->next;
    }
}
int main()
{
    Node *list = initlist();
    Node *tail = get_tail(list);
    tail = insertelem(tail, 10);
    tail = insertelem(tail, 20);
    listNode(list);
    return 0;
}