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
	ElemType data;//�洢����
	struct LNode *next;//ָ����һ������ָ��
}LNode,*LinkList;

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

//ɾ��λ��Ϊi��Ԫ�أ�����ɾ��Ԫ�ظ���e
Status ListDelete_L(LinkList &L, int i, ElemType &e)
{
	LinkList p, q;
	p = L;   int j = 0;
	while (p->next && j<i - 1) { p = p->next; ++j; }
	if (!(p->next) || j> i - 1) return ERROR;
	q = p->next;	p->next = q->next;
	e = q->data;	free(q);
	return OK;
}//ListDelete_L

//����Ԫ�أ�����λ��i
int LocateElem_L(LinkList L, ElemType e)
{
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		if (p->data==e)
			return i;
		p = p->next;
	}
	return 0;
}//LocateElem_L

//�������������ֵ
void ListOutput_L(LinkList&L)
{
	LinkList p;
	p = L->next;
	while (p)
	{
		cout << p->data<<" ";
		p = p->next;
	}
	cout << endl;
}//ListOutput_L

//��������е�Ԫ�ظ���
int ListNumber_L(LinkList&L)
{
	LinkList p;
	int i=0;
	p = L->next;
	while (p) { i++; p = p->next; }
	return i;
}//ListNumber_L

int main()
{
	LinkList La;
	int n,i,x,j,m,y,z;
	cin >> n;
	InitList_L(La);
	CreateList_L(La, n);
	ListOutput_L(La);
	cin >> i >> x;
	if (ListInsert_L(La, i, x))
	{
		ListOutput_L(La);
	}
	else cout << -1 << endl;
	cin >> j;
	if (ListDelete_L(La, j, m))
	{
		ListOutput_L(La);
	}
	else cout << -1 << endl;
	cin >> y;
	z = LocateElem_L(La, y);
	if (z) cout<<z<<endl;
	else cout << -1 << endl;
	cout<<ListNumber_L(La)<<endl;
	system("pause");
	return 0;
}