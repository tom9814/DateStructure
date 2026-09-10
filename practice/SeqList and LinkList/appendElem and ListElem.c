include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;
//˳����Ķ��� 
typedef struct{
	ElemType date[MAXSIZE];
	int length;
}SeqList;
//˳�����ʼ��
void initList(SeqList *L)
{
	L->length = 0;
} 
//˳�������Ԫ��
int appendElem(SeqList *L, ElemType elem)
{
	if(L->length > MAXSIZE)
	{
		printf("װ��������\n");
		return 0;
	}
	L->date[L->length] = elem;
	L->length++;
	return 1;
} 
//˳�������Ԫ��
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
	printf("˳����ѳ�ʼ����Ŀǰ����Ϊ%d\n", list.length);
	printf("˳���ռ%zu�ֽ�\n", sizeof(list));
	appendElem(&list,15);
	appendElem(&list,23);
	appendElem(&list,87);
	appendElem(&list,93);
	ListElem(&list);
	return 0;
}
