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

int main()
{
	SeqList list;
	initList(&list);
	printf("顺序表已初始化，目前长度为%d\n", list.length);
	printf("顺序表占%zu字节", sizeof(list));
	return 0;
}
