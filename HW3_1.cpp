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
	ElemType data;//存储数据
	struct LNode *next;//指向下一个结点的指针
}LNode,*LinkList;

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

//在i位置插入元素e
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

//删除位置为i的元素，将被删除元素赋给e
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

//查找元素，返回位置i
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

//输出链表中所有值
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

//输出链表中的元素个数
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