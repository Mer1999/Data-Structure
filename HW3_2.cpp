#include <iostream>
using namespace std;

#define TRUE         1
#define FALSE        0
#define OK           1
#define ERROR        0
#define INFEASIBLE  -1
#define OVERFLOW	  -2

typedef int Status;
typedef int ElemType;

//��������
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

//��������������
void CreateList_L(LinkList&L, int n)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = n; i > 0; --i) {
		LinkList p = (LinkList)malloc(sizeof(LNode));
		cin >> p->data;
		p->next = L->next; L->next = p;
	}
}//CreateList_L

 //��ʼ������
Status InitList_L(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode)); /* ����ͷ���,��ʹLָ���ͷ���*/
	if (!L) /* �洢����ʧ��*/
		exit(OVERFLOW);
	L->next = NULL; /* ָ����Ϊ��*/
	return OK;
}//InitList_L

 //��������е�Ԫ�ظ���
int ListNumber_L(LinkList&L)
{
	LinkList p;
	int i = 0;
	p = L->next;
	while (p) { i++; p = p->next; }
	return i;
}//ListNumber_L

 //�������������ֵ
void ListOutput_L(LinkList&L)
{
	LinkList p;
	p = L->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}//ListOutput_L

 //����������
Status ListTurn_L(LinkList& L)
{
	LinkList top_ = L->next, end_ = L->next;
	int n, len = ListNumber_L(L), m = len / 2, i;
	for (i = 0; i < len / 2; i++)end_ = end_->next;
	while (m)
	{
		for (i = 0, top_ = L->next; i < m - 1; i++)
			top_ = top_->next;
		n = top_->data;
		top_->data = end_->data;
		end_->data = n;
		end_ = end_->next;
		m--;
	}
	return OK;
}//ListTurn_L

 //�������Ϊ���ı�����Ԫ��
void ListTri_L(LinkList&L)
{
	LinkList p;
	p = L->next;
	while (p)
	{
		if (p->data % 3 == 0)
		{
			cout << p->data << " ";
		}
		p = p->next;
	}
	cout << endl;
}//ListTri_L

 //�������ɾ��
Status ListDestroy_L(LinkList&L)
{
	LinkList q;
	while (L)
	{
		q = L->next;
		free(L);
		L = q;
	}
	return OK;
}//ListDestroy_L

int main()
{
	LinkList La;
	int n;
	cin >> n;
	InitList_L(La);
	CreateList_L(La, n);
	ListOutput_L(La);
	ListTurn_L(La);
	ListTri_L(La);
	ListDestroy_L(La);
	system("pause");
	return 0;
}