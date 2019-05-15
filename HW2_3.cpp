#include <iostream>
using namespace std;

#define TRUE         1
#define FALSE        0
#define OK           1
#define ERROR        0
#define INFEASIBLE  -1
#define OVERFLOW	  -2
#define LIST_INIT_SIZE		100		//线性表存储空间初始分配
#define LIST_INCREMENT	 	10		//线性表存储空间再分配

typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType	*elem;
	int			length;
	int			listsize;
}SqList;

//构建一个新的空顺序表
Status InitList_Sq(SqList &L)
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}//InitList_Sq

 //在第i个元素的位置插入一个元素
Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
	if (i<1 || i>L.length + 1)return ERROR;
	if (L.length >= L.listsize)
	{
		ElemType *newbase = (ElemType*)realloc(L.elem, (L.listsize + LIST_INCREMENT) * sizeof(ElemType));
		if (!newbase)exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LIST_INCREMENT;
	}
	ElemType *q = &(L.elem[i - 1]), *p;
	for (p = &(L.elem[L.length - 1]); p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++L.length;
	return OK;
}//ListInsert_Sq

 //顺序表的销毁
Status DestoryList_Sq(SqList &L)
{
	if (L.elem == NULL)return ERROR;
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}//DestoryList_Sq

 //合并La,Lb得到Lc
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc) {
	int* pa, *pb, *pc, *pa_last, *pb_last;
	pa = La.elem; pb = Lb.elem;
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType*)malloc(Lc.listsize * sizeof(ElemType));
	if (!Lc.elem)exit(OVERFLOW);
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last)
	{
		if (*pa <= *pb)*pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while (pa <= pa_last)*pc++ = *pa++;
	while (pb <= pb_last)*pc++ = *pb++;
}//MergeList_Sq

int main()
{
	SqList La, Lb, Lc;
	int ins, i;
	InitList_Sq(La);
	InitList_Sq(Lb);
	while (1)
	{
		cin >> ins;
		if (ins == 0)break;
		for (i = 0; i < La.length; i++)
		{
			if (ins <= La.elem[i]) break;
		}
		ListInsert_Sq(La, i + 1, ins);
	}
	while (1)
	{
		cin >> ins;
		if (ins == 0)break;
		for (i = 0; i < Lb.length; i++)
		{
			if (ins <= Lb.elem[i]) break;
		}
		ListInsert_Sq(Lb, i + 1, ins);
	}
	MergeList_Sq(La, Lb, Lc);
	for (i = 0; i < Lc.length; i++)
	{
		cout << Lc.elem[i] << " ";
	}
	DestoryList_Sq(La);
	DestoryList_Sq(Lb);
	DestoryList_Sq(Lc);
	system("pause");
	return 0;
}