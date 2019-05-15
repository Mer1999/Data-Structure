#include <iostream>
using namespace std;

#define TRUE         1
#define FALSE        0
#define OK           1
#define ERROR        0
#define INFEASIBLE  -1
#define OVERFLOW	  -2
#define LIST_INIT_SIZE		10000		//���Ա�洢�ռ��ʼ����
#define LIST_INCREMENT	 	10000		//���Ա�洢�ռ��ٷ���

typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType	*elem;
	int			length;
	int			listsize;
}SqList;

//����һ���µĿ�˳���
Status InitList_Sq(SqList &L)
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}//InitList_Sq

 //�ڵ�i��λ�ò���һ��Ԫ��
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

 //ɾ����i��Ԫ�أ�����e������ֵ
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

 //����Ԫ��e
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

 //˳��������
Status DestoryList_Sq(SqList &L)
{
	if (L.elem == NULL)return ERROR;
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}//DestoryList_Sq

 //ɾ���������е�Ԫ��e
void Delete_Sq(SqList &L, ElemType e)
{
	int i = 0, index = 0;
	if (ListFind_Sq(L, i, e))
	{
		for (i = 0; i < L.length; i++)
		{
			if (L.elem[i] != e)
			{
				L.elem[index++] = L.elem[i];
			}
		}
		L.length = index;
		for (i = 0; i < L.length; i++) { cout << L.elem[i] << " "; }
	}
	else cout << -1 << endl;
}//Delete_Sq


int main()
{
	SqList La;
	int num, elem, i, del;
	InitList_Sq(La);
	cin >> num;
	La.length = num;
	for (i = 0; i < num; i++) {
		cin >> La.elem[i];
	}
	cin >> del;
	Delete_Sq(La, del);
	DestoryList_Sq(La);
	system("pause");
	return 0;
}