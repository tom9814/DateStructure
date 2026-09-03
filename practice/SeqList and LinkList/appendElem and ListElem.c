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
	if(L->length > MAXSIZE)
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
	return 0;
}
