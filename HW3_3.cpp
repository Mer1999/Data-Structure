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

//在i位置插入元素e
Status ListInsert_L(LinkList &L, int i, ElemType e)
{
	LinkList p, s;
	p = L;   int j = 0;
	while (p && j<i - 1) {
		p = p->next;
		++j;
	}
	if (!p || j> i - 1) return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e; s->next = p->next;
	p->next = s;
	return OK;
}//ListInsert_L

 /*建立单线性无重复链表
 void CreateList_L(LinkList&L, int n)
 {
 L = (LinkList)malloc(sizeof(LNode));
 L->next = NULL;
 LinkList q;
 int m;
 LinkList p = (LinkList)malloc(sizeof(LNode));
 cin >> p->data;
 p->next = L->next;
 L->next = p;
 for (int i = n-1; i > 0; --i) {
 LinkList p = (LinkList)malloc(sizeof(LNode));
 cin >> p->data;
 q = L->next;
 while (q)
 {
 m = 1;
 if (q->data == p->data)
 {
 m = 0;
 break;
 }
 q = q->next;
 }
 if (m) { p->next = L->next; L->next = p; }
 }
 }//CreateList_L*/

 //初始化链表
Status InitList_L(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode)); /* 产生头结点,并使L指向此头结点*/
	if (!L) /* 存储分配失败*/
		exit(OVERFLOW);
	L->next = NULL; /* 指针域为空*/
	return OK;
}//InitList_L

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

 //链表去重
Status RepeteDelete_L(LinkList L)
{
	LinkList p = L->next, q, r;
	int n;
	while (p->next)
	{
		n = 1;
		for (q = L->next; q != p->next; q = q->next)
		{
			if (q->data == p->next->data)
			{
				r = p->next;
				p->next = r->next;
				free(r);
				n = 0;
				break;
			}
		}
		if (n)p = p->next;
	}
	return OK;
}//RepeteDelete_L

int main()
{
	LinkList La;
	int n, e;
	cin >> n;
	InitList_L(La);
	for (int i = 1; i <= n; i++)
	{
		cin >> e;
		ListInsert_L(La, i, e);
	}
	RepeteDelete_L(La);
	ListOutput_L(La);
	system("pause");
	return 0;
}