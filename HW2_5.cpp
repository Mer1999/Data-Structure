#include <iostream>
using namespace std;

#define TRUE         1
#define FALSE        0
#define OK           1
#define ERROR        0
#define INFEASIBLE  -1
#define OVERFLOW	  -2
#define LIST_INIT_SIZE		10000		//线性表存储空间初始分配
#define LIST_INCREMENT	 	10000		//线性表存储空间再分配

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

 //顺序表的销毁
Status DestoryList_Sq(SqList &L)
{
	if (L.elem == NULL)return ERROR;
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}//DestoryList_Sq

 //删除表中所有重复元素
void DeleteSame_Sq(SqList &L, int n)
{
	int ele, j;
	for (int i = 0; i < n; i++)
	{
		cin >> ele;
		for (j = 0; j < L.length; j++)
		{
			if (L.elem[j] == ele)break;
		}
		if (j == L.length)
		{
			L.elem[j] = ele;
			L.length++;
		}
	}
}//DeleteSame_Sq


int main()
{
	SqList La;
	int num, i;
	InitList_Sq(La);
	cin >> num;
	DeleteSame_Sq(La, num);
	for (i = 0; i < La.length; i++)
	{
		cout << La.elem[i] << " ";
	}
	DestoryList_Sq(La);
	system("pause");
	return 0;
}