#include <stdio.h>
#include <stdlib.h>
typedef int elemtype;
typedef struct node
{
    elemtype date;
    struct node *next;
}Node;
//链表初始化
Node* initlist()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->date = 0;
    head->next = NULL;
    return head;
}
//链表头插法插入数据
void insertelem(Node* L, elemtype e)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->date = e;
    p->next = L->next;
    L->next = p;
} 
//链表遍历
void listNode(Node *L)
{
    Node* p = L->next;
    while (p != NULL)
    {
        printf("%d\n", p->date);
        p = p->next;
    }    
}
int main()
{
    Node *list = initlist();
    insertelem(list,10);
    insertelem(list,20);
    listNode(list);
    return 0;
}