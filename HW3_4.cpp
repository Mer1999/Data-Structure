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
	L->next = NULL; /* ָ����Ϊ��*/
	return OK;
}//InitList_L

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

 //������������
void OrderInsert_L(LinkList &L, ElemType e)
{
	LinkList q = L, p = L->next;
	while (p&&e>p->data)
	{
		q = p;
		p = p->next;
	}
	q->next = (LinkList)malloc(sizeof(LNode));
	q->next->data = e;
	q->next->next = p;
}//OrderInsert_L


 //�ϲ�����
void MergeList_L(LinkList&La, LinkList&Lb, LinkList&Lc) {
	LinkList pa = La->next;
	LinkList pb = Lb->next;
	LinkList pc;
	Lc = pc = La;
	while (pa&&pb) {
		if (pa->data <= pb->data) {
			pc->next = pa; pc = pa; pa = pa->next;
		}
		else { pc->next = pb; pc = pb; pb = pb->next; }
	}
	pc->next = pa ? pa : pb;
	free(Lb);
}//MergeList_L

int main()
{
	LinkList La, Lb, Lc;
	int ele;
	InitList_L(La);
	InitList_L(Lb);
	InitList_L(Lc);
	while (1)
	{
		cin >> ele;
		if (ele == 0) { break; }
		OrderInsert_L(La, ele);
	}
	while (1)
	{
		cin >> ele;
		if (ele == 0) { break; }
		OrderInsert_L(Lb, ele);
	}
	MergeList_L(La, Lb, Lc);
	ListOutput_L(Lc);
	system("pause");
	return 0;
}