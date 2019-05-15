#include <iostream>
using namespace std;

#define TRUE         1
#define FALSE        0
#define OK           1
#define ERROR        0
#define INFEASIBLE  -1
#define OVERFLOW	  -1
#define LIST_INIT_SIZE		100		//���Ա�洢�ռ��ʼ����
#define LIST_INCREMENT	 	10		//���Ա�洢�ռ��ٷ���

typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType	*elem;//���Ա�Ԫ��
	int			length;//���Ա���
	int			listsize;//���Ա�����
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

 //�ڵ�i��Ԫ��֮ǰ����һ��Ԫ��
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

 //ɾ����i��Ԫ�أ�����e
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

 //���ҵ�i��Ԫ��
Status ListFind_Sq(SqList &L, int &i, ElemType e)
{
	if ((i < 1) || (i > L.length))return ERROR;
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
	int i;
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}//DestoryList_Sq

int main()
{
	SqList L;
	int n, i, x, j, y, k, l;
	InitList_Sq(L);
	cin >> n;
	for (k = 0; k < n; k++)
	{
		cin >> x;
		ListInsert_Sq(L, L.length + 1, x);
	}
	cin >> i >> l;
	cin >> j;
	cin >> y;

	cout << endl;
	for (k = 0; k < L.length; k++)cout << L.elem[k] << " ";
	cout << endl;

	if (ListInsert_Sq(L, i, l))
	{
		for (k = 0; k < L.length; k++)cout << L.elem[k] << " ";
		cout << endl;
	}
	else
		cout << -1 << endl;

	if (ListDelete_Sq(L, j, x))
	{
		for (k = 0; k < L.length; k++)cout << L.elem[k] << " ";
		cout << endl;
	}
	else
		cout << -1 << endl;

	if (ListFind_Sq(L, i, y))
		cout << i << endl;
	else
		cout << -1 << endl;

	DestoryList_Sq(L);
	system("pause");
	return 0;
}