#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef int elemtpye;
typedef struct node
{
    elemtpye data;
    struct node *next, *prev;
}Node;
//双向链表的初始化
Node *initlist()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

//双向链表的头插法
void inserthead(Node *head, elemtpye e)
{
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = e;
    new->prev = head;
    new->next = head->next;
    if(head->next != NULL)
    {
        head->next->prev = new;
    }
    head->next = new;
}

//双向链表的尾插法
Node *gettail(Node *head)
{
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

Node *inserttail(Node *tail, elemtpye data)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->prev = tail;
    p->next = NULL;
    tail->next = p;
    return p;
} 

//双向链表插入数据
int insertNode(Node *head, elemtpye data, int pos)
{   
    Node *p = head;
    for(int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        if (p == NULL)
        {
            printf("插入位置错误\n");
            return 0;
        }
        
    }
    Node *q = (Node*)malloc(sizeof(Node));
    q->data = data;
    q->prev = p;
    q->next = p->next;
    p->next = q;
    q->next->prev = q;
    return 1;
}

//删除指定位置的节点
int deleteNode(Node *head, int pos)
{
    Node *p = head;
    for(int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        if(p->next == NULL)
        {
            printf("删除位置错误");
            return 0;
        }
    }
    Node *q = p->next;
    p->next = q->next;
    q->next->prev = p;
    free(q);
    return 1;
}

//双向链表的遍历
void listNode(Node *head)
{
    Node *p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Node *list = initlist();
    Node *tail = gettail(list);
    tail = inserttail(tail,1);
    tail = inserttail(tail,2);
    tail = inserttail(tail,3);
    tail = inserttail(tail,4);
    tail = inserttail(tail,5);
    listNode(list);
    insertNode(list,9,3);
    listNode(list);
    deleteNode(list,4);
    listNode(list);
    system("pause");
    return 0;
}