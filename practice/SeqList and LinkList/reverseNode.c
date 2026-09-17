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
    Node *p = (Node*)malloc(sizeof(Node));
    p->date = e;
    tail->next = p;
    p->next = NULL;
    return p;
}
//指定位置插入元素
void insertNode(Node *L, int pos, elemtype e)
{
    Node *p = L;
    for(int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }
    Node *q = (Node*)malloc(sizeof(Node));
    q->date = e;
    q->next = p->next;
    p->next = q;
}
//链表删除数据
int DeleteNode(Node *L, int pos)
{
    //让p指向要删除位置的前驱节点
    Node *p = L;
    for(int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        if(p == NULL)
        {
            return 0;
        }
    }
    if(p->next == NULL)
    {
        return 0;
    }
    Node *q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

//反转链表
Node *reverseNode(Node *head)
{
    Node *first = NULL;
    Node *second = head->next;
    //third先初始化，不急着给值
    Node *third = NULL;
    while (second != NULL)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    Node *reversedhead = initlist();
    reversedhead->next = first;
    return reversedhead;
}
// 链表遍历
void listNode(Node *L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->date);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    Node *list = initlist();
    Node *tail = get_tail(list);
    tail = insertelem(tail, 1);
    tail = insertelem(tail, 2);
    tail = insertelem(tail, 3);
    tail = insertelem(tail, 4);
    tail = insertelem(tail, 5);
    tail = insertelem(tail, 6);
    listNode(list);
    Node *reversedlist = reverseNode(list);
    listNode(reversedlist);
    return 0;
}