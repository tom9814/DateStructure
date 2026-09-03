#include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;
//顺序表的定义 
typedef struct{
	ElemType date[MAXSIZE];
	int length;
}SeqList;
//顺序表初始化
void initList(SeqList *L)
{
	L->length = 0;
} 
//顺序表添加元素
int appendElem(SeqList *L, ElemType elem)
{
	if(L->length >= MAXSIZE)
	{
		printf("装不下啦！\n");
		return 0;
	}
	L->date[L->length] = elem;
	L->length++;
	return 1;
} 
//顺序表遍历元素
void ListElem(SeqList *L)
{
	for(int i = 0; i < L->length; i++)
	{
		printf("%d ",L->date[i]);
	}
	printf("\n");
} 
//顺序表插入元素
int insertElem(SeqList *L, int pos, ElemType elem)
{
	if(L->length >= MAXSIZE)
	{
		printf("表已经满啦！\n");
		return 0;
	}
	if(pos < 1 || pos > L->length + 1)
	{
		printf("插入位置错误!\n");
		return 0;
	}
	for(int i = L->length - 1; i >= pos - 1; i--)
	{
		L->date[i + 1] = L->date[i];
	}
	L->date[pos - 1] = elem;
	L->length++;
	return 1;
} 
//顺序表删除元素
int deleteElem(SeqList *L, int pos, ElemType *elem)
{	
	if(L->length == 0)
	{
		printf("空表!");
		return 0;
	}
	if(pos > L->length)
	{
		printf("删除位置错误");
		return 0;
	}
	*elem = L->date[pos - 1];
	for(int i = pos; i < L->length; i++)
	{
		L->date[i - 1] = L->date[i];
	}
	L->length--;
	return 1;
} 
int main()
{
	SeqList list;
	initList(&list);
	printf("顺序表已初始化，目前长度为%d\n", list.length);
	printf("顺序表占%zu字节\n", sizeof(list));
	appendElem(&list,15);
	appendElem(&list,23);
	appendElem(&list,87);
	appendElem(&list,93);
	ListElem(&list);
	insertElem(&list,5,88);
	ListElem(&list);
	ElemType deleteelem;
	deleteElem(&list, 3, &deleteelem);
	ListElem(&list);
	printf("被删除元素为%d", deleteelem);
	return 0;
}
