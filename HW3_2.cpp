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

//单链表定义
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

//建立单线性链表
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

 //初始化链表
Status InitList_L(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode)); /* 产生头结点,并使L指向此头结点*/
	if (!L) /* 存储分配失败*/
		exit(OVERFLOW);
	L->next = NULL; /* 指针域为空*/
	return OK;
}//InitList_L

 //输出链表中的元素个数
int ListNumber_L(LinkList&L)
{
	LinkList p;
	int i = 0;
	p = L->next;
	while (p) { i++; p = p->next; }
	return i;
}//ListNumber_L

 //输出链表中所有值
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

 //将链表逆序
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

 //输出所有为三的倍数的元素
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

 //单链表的删除
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