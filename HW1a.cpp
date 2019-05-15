#include<iostream>
#include<string>
using namespace std;

#define TRUE         1
#define FALSE        0
#define OK           1
#define ERROR        0
#define INFEASIBLE  -1
#define OVERFLOW	  -2
int STACK_INIT_SIZE;//顺序栈的初始大小

typedef int Status;
typedef int SElemType;

typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

//构造一个空栈
Status InitStack(SqStack &S) {
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) return (OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}//InitStack

 //插入e为新的栈顶元素
Status Push(SqStack &S, SElemType e) {
	if (S.top - S.base >= S.stacksize) return ERROR;
	*S.top++ = e;
	return OK;
}//Push

 //若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
Status Pop(SqStack&S, SElemType &e) {
	if (S.top == S.base)return ERROR;
	e = *--S.top;
	return OK;
}//Pop

//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
Status GetTop(SqStack S, SElemType &e) {
	if (S.top == S.base)return ERROR;
	e = *(S.top - 1);
	return OK;
}//GetTop

//遍历栈
void OutStack(SqStack S) {
	while (S.top != S.base) {
		cout << *--S.top << " ";
	}
	cout << endl;
}//OutStack

//检验是否栈满，若满则返回0，否则返回1
Status CheckFull(SqStack S) {
	if (S.top - S.base >= S.stacksize) return ERROR;
	else return OK;
}//CheckFull

//检验是否栈空，若空则返回0，,否则返回1
Status CheckEmpty(SqStack S) {
	if (S.top == S.base)return ERROR;
	else return OK;
}//CheckEmpty

//判断转移是否合理，若合理则返回1，否则返回0
Status CheckMove(SqStack A, SqStack B) {
	int ea, eb;
	if (CheckEmpty(A) && CheckEmpty(B)) {
		GetTop(A, ea);
		GetTop(B, eb);
		if (ea > eb) return ERROR;
		else return OK;
	}
	else return OK;
}//CheckMove

int main() {
	int n=0, k,elem,a,b,ea,eb;//n为柱子个数，k为圆盘个数，elem为输入圆盘大小，a,b为移动时操作的柱子，ea为a柱最顶端的圆盘，eb为b柱最顶端的圆盘
	string order=" ";
	SqStack hano[1000];
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> STACK_INIT_SIZE;
		InitStack(hano[i]);
	}
	for (int i = 0; i < k; i++) {
		cin >> elem;
		Push(hano[0], elem);
	}//准备工作完成
	while (1) {
		cin >> order;
		if (order == "MOVE") {
			cin >> a >> b;
			if (!GetTop(hano[a - 1], ea)) cout << a << " IS EMPTY" << endl;
			if(!CheckFull(hano[b-1])) cout<<b<<" IS FULL"<<endl;
			if (!CheckMove(hano[a - 1], hano[b - 1]))cout << "ILLEGAL" << endl;
			if (GetTop(hano[a - 1], ea) && CheckFull(hano[b - 1])&&CheckMove(hano[a-1],hano[b-1])) {
						Pop(hano[a - 1], ea);
						Push(hano[b - 1], ea);
						cout << ea << endl;
			}
		}//MOVE
		if (order == "DISPLAY") {
			cin >> a;
			if (!CheckEmpty(hano[a - 1])) cout << 0 << endl;
			else OutStack(hano[a - 1]);
		}
		if (order == "QUIT") {
			for (int i = 0; i < n; i++) {
				if (!CheckEmpty(hano[i]))cout << 0 << endl;
				else OutStack(hano[i]);
			}
			break;
		}
	}//while
	system("pause");
	return 0;
}