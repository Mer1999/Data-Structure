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

 //在第i个元素之前插入一个元素
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

 //删除第i个元素，并用e返回其值
Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
	if ((i < 1) || (i > L.length))return ERROR;
	ElemType *p = &(L.elem[i - 1]), *q = L.elem + L.length - 1;
	e = *p;
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--L.length;
	return OK;
}//ListDelete_Sq

 //查找元素e
Status ListFind_Sq(SqList &L, int &i, ElemType e)
{
	int j = 0;
	while (j < L.length)
	{
		if (*(L.elem + j) == e)
		{
			i = j + 1;
			return OK;
		}
		j++;
	}
	return ERROR;
}//ListFind_Sq

 //顺序表的销毁
Status DestoryList_Sq(SqList &L)
{
	if (L.elem == NULL)return ERROR;
	int i;
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}//DestoryList_Sq


int main()
{
	SqList orderlist;
	int ins, i, del;
	InitList_Sq(orderlist);
	while (1)
	{
		cin >> ins;
		if (ins == 0)break;
		for (i = 0; i < orderlist.length; i++)
		{
			if (ins <= orderlist.elem[i]) break;
		}
		ListInsert_Sq(orderlist, i + 1, ins);
	}
	cin >> ins;
	for (i = 0; i < orderlist.length; i++)
	{
		if (ins <= orderlist.elem[i])break;
	}
	ListInsert_Sq(orderlist, i + 1, ins);
	cout << i + 1 << endl;
	cin >> del;
	if (ListFind_Sq(orderlist, i, del))
	{
		ListDelete_Sq(orderlist, i, del);
		cout << i << endl;
	}
	else cout << -1 << endl;
	for (i = 0; i < orderlist.length; i++)
	{
		cout << orderlist.elem[i] << " ";
	}
	DestoryList_Sq(orderlist);
	system("pause");
	return 0;
}