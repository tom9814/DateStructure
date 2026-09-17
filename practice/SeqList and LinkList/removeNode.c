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
// 指定位置插入元素
void insertNode(Node *L, int pos, elemtype e)
{
    Node *p = L;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }
    Node *q = (Node *)malloc(sizeof(Node));
    q->date = e;
    q->next = p->next;
    p->next = q;
}
// 链表删除数据
int DeleteNode(Node *L, int pos)
{
    // 让p指向要删除位置的前驱节点
    Node *p = L;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        if (p == NULL)
        {
            return 0;
        }
    }
    if (p->next == NULL)
    {
        return 0;
    }
    Node *q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

//删除绝对值一样的节点
void removeNode(Node *L, int n)
{
    int *q = (int*)malloc(sizeof(int) * (n + 1));
    //初始化放数的数组
    for(int i = 0; i < n + 1; i++)
    {
        *(q + i) = 0;
    }
    Node *p = L;
    int index = 0;
    while(p ->next != NULL)
    {
        index = abs(p->next->date);
        if(*(q + index) == 0)
        {
            *(q + index) = 1;
            p = p->next;
        }
        else
        {
            Node *temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    free(q);
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
    tail = insertelem(tail, -10);
    tail = insertelem(tail, 10);
    tail = insertelem(tail, 20);
    tail = insertelem(tail, 30);
    tail = insertelem(tail, -10);
    listNode(list);
    removeNode(list,30);
    listNode(list);
    return 0;
}