#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
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
//获取链表长度(包含头节点)
int linklistlenghth(Node *L)
{
    Node *p = L;
    int len = 1;
    while (p->next != NULL)
    {
        len++;
        p = p->next;
    }
    return len;    
}
//释放链表
int freelinklist(Node *L)
{
    Node *p = L -> next;
    Node *q;
    while (p ->next != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(p);
    L->next = NULL;
    return 1;
}
//查找倒数第k个节点
int findNodeFS(Node *L, int k)
{
    Node *p = L->next;
    Node *q = L->next;
    for(int i = 0; i < k; i++)
    {
        q = q->next;
    }
    while (q != NULL)
    {
        p = p->next;
        q = q->next;
    }
    printf("倒数第%d个节点里的date为%d",k,p->date);
    return 1; 
}
int main()
{   
    SetConsoleOutputCP(CP_UTF8);
    Node *list = initlist();
    Node *tail = get_tail(list);
    tail = insertelem(tail, 10);
    tail = insertelem(tail, 20);
    tail = insertelem(tail, 30);
    tail = insertelem(tail, 40);
    findNodeFS(list,2);
    return 0;
}