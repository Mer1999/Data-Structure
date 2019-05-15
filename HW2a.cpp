#include <iostream>
#include <string.h>
using namespace std;

#define TRUE         1
#define FALSE        0
#define OK           1
#define ERROR        0
#define INFEASIBLE  -1
#define OVERFLOW      -1

int STACK_INIT_SIZE = 10000;        //�洢�ռ��ʼ����

typedef int Status;

typedef struct
{
	int    weight;                        //Ȩֵ
	int    parent, lchild, rchild;
}HTNode, *HuffmanTree;                            //��̬��������洢��������
typedef char **HuffmanCode;                        //��̬��������洢�����������

//��0/1ת��Ϊ����
void code2str(HuffmanTree HT, char *(str1), int n)
{
	char ch[1000];
	int m = 2 * n - 1, p = m, i = 0;
	cin >> ch;
	while (ch[i])
	{
		if (ch[i] == '0')
			p = HT[p].lchild;
		else
			p = HT[p].rchild;
		if (p <= n)
		{
			cout << str1[p - 1];
			p = m;
		}
		i++;
	}
	cout << endl;
}

//�ɹ��������빹����������
void code2tree(HuffmanTree &HT, char *(&str))
{
	int n;
	cin >> n;
	int m = 2 * n - 1, i, j, k, p, unuse_p = m - 1;
	char str_in[100];
	HuffmanTree HTp;

	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	str = (char*)malloc((n) * sizeof(char));

	//1��m���鵥Ԫ����
	for (HTp = HT + 1, i = 1; i <= m; i++, HTp++)
		*HTp = { 0,0,0,0 };

	for (i = 0; i < n; i++)
	{
		cin >> k >> str_in;
		str[i] = k;
		p = m;
		//ǰ����0/1
		for (j = 0; str_in[j + 1]; j++)
		{
			if (str_in[j] == '0')
			{
				if (HT[p].lchild == 0)
					HT[p].lchild = unuse_p--;
				p = HT[p].lchild;
			}
			else {
				if (HT[p].rchild == 0)
					HT[p].rchild = unuse_p--;
				p = HT[p].rchild;
			}
		}
		//���һ��0/1
		if (str_in[j] == '0')
			HT[p].lchild = i + 1;
		else
			HT[p].rchild = i + 1;
	}
	code2str(HT, str, n);
}

int main()
{
	HuffmanTree HT;
	char *str;
	code2tree(HT, str);
	system("pause");
	return 0;
}