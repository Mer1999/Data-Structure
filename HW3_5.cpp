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

//��ʼ������
Status InitList_L(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode)); /* ����ͷ���,��ʹLָ���ͷ���*/
	if (!L) /* �洢����ʧ��*/
		exit(OVERFLOW);
	L->next = L; /* ָ����Ϊ��*/
	return OK;
}//InitList_L

 //��iλ�ò���Ԫ��e
Status ListInsert_L(LinkList &L, int i, ElemType e)
{
	LinkList p, s;
	p = L;   int j = 0;
	while (p && j<i - 1) { p = p->next; ++j; }
	if (!p || j> i - 1) return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e; s->next = p->next;
	p->next = s;
	return OK;
}//ListInsert_L

int main()
{
	int s, m, n, i;
	LinkList p, q, La;
	InitList_L(La);
	p = La;
	cin >> n >> s >> m;
	for (i = 0; i < n; i++)
	{
		ListInsert_L(La, 1 + i, 1 + i);
	}
	for (i = 0; i < s - 1; i++)
	{
		p = p->next;
		if (p->next == La)p = p->next;
	}
	while (p->next != p)
	{
		for (i = 0; i < m - 1; i++)
		{
			p = p->next;
			if (p->next == La)p = p->next;
		}
		cout << p->next->data << " ";
		q = p->next;
		p->next = q->next;
		free(q);
		if (p->next == La)p = p->next;
	}
	cout << endl;
	system("pause");
	return 0;
}