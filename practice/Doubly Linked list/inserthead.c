#include <stdio.h>
#include <stdlib.h>
typedef int elemtpye;
typedef struct node
{
    elemtpye data;
    struct node *next, *prev;
}Node;
//双向链表的初始化
Node* initlist()
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
    inserthead(list,1);
    inserthead(list,2);
    inserthead(list,3);
    inserthead(list,4);
    inserthead(list,5);
    listNode(list);
    return 0;
}