#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
	char num;
	int isGood;	//判断是否为好人，isGood为1好人
	node* next;
};

struct node* create(int n, char num[]) //创建带头结点的循环单链表
{
	int i;
	node* current;	//当前插入的位置指针
	node* tail;	//尾指针
	node* head;	//头指针
	head = new node;	//新建头结点
	head->next = NULL;
	current = head;	//当指头
	tail = head;	//尾指头
	for (i = 0; i < n; i++)	//采用尾插法
	{
		node* p;
		p = new node;
		p->num = num[i];
		p->isGood = 1;
		p->next = current->next;
		current->next = p;
		current = p;
	}
	current->next = head;	//完成循环
	return head;
}

void arraylist(node* head, int n, int m)	//n为人数，m为步长
{
	node* p = head->next;
	int count = 1;
	int len = n;
	while (len > 0) {
		if (count == m)//数到步长
		{
			if (p->isGood != -1)//是好人
			{
				p->isGood = -1;//放坏人
				count = 1;
				len--;
			}
			p = p->next;
		}
		else if (count < m)
		{
			if (p->isGood != -1)//是好人
			{
				count++;
			}
			p = p->next;
		}

		if (p == head)//保证循环链表
			p = p->next;
	}
	//接下来根据isGood进行赋值处理

	struct node* q = head->next;
	int cnt = 1;
	while (q != head)
	{
		if (q->isGood == -1)
		{
			q->num = 'B';
		}
		if (cnt == 50)
		{
			cout << q->num << endl;
			cnt = 1;//这边注意输出格式为50个一行
		}
		else
		{
			cout << q->num;
			cnt++;
		}
		q = q->next;
	}
}

int main() {
	int n, m;	//n为人数，m为步长  n<=32767
	cin >> n >> m;
	int len = 2 * n;
	char arr[200000];
	for (int i = 0; i < len; i++)
	{
		arr[i] = 'G';	//目标数组进行初始化
	}
	node* list = create(len,arr);	//总长度为len
	arraylist(list, n, m);	//这里保证最后的人数为n个好人
	return 0;
}