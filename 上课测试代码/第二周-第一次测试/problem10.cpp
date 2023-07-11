#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
	int num;
	int power;
	ListNode* next;
};

ListNode* createByArray(int arr1[], int arr2[], int n)
{
	ListNode* head;
	head = new ListNode;
	head->next = NULL;
	ListNode* r;	//r为指向尾结点的指针
	r = head;
	ListNode* p;	//p为指向待插入结点的指针
	for (int i = 0; i < n; i++)
	{
		p = new ListNode;
		p->num = arr1[i];
		p->power = arr2[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;	
	return head;
}

void displayLink(ListNode* head) {
	ListNode* p;
	p = head->next;
	if (p == NULL) {
		cout << "0 0" << endl;
		cout << endl;
		return;
	}
	while (p != NULL) {
		cout << p->num << " " << p->power << endl;
		p = p->next;
	}
	cout << endl;
}

void fun(ListNode* la, ListNode* lb, int op) {
	//求并，并将结果放在la中
	ListNode* p, * q;
	if (!la->next) {
		la->next = lb->next;
		delete lb;	//lb的头结点删除
		return;
	}
	p = lb;
	lb = lb->next;
	delete p;	//释放lb的头结点
	while (lb != NULL) {
		p = lb;
		lb = lb->next;
		q = la->next;
		while (q != NULL && q->power != p->power)	//找到p，q阶数相同的
			q = q->next;
		if (q == NULL)	//找不到对应的
		{
			p->next = la->next;
			la->next = p;
		}
		else {
			if (op == 0) {
				q->num += p->num;
			}
			else {
				q->num -= p->num;
			}
			delete p;
		}
	}

	//去除零结点
	ListNode* pre;
	p = la->next;
	pre = la;
	while (p != NULL) {
		if (p->num == 0) {
			pre->next = p->next;
			delete p;
			p = pre->next;
		}
		else {
			pre = pre->next;
			p = p->next;
		}
	}
}

//将s指向的结点插入到有序链表中，并保持链表按num有序
void insertNodeInOrder(ListNode* head, ListNode* s)
{
	ListNode* p1, * p2;
	p2 = head;
	p1 = head->next;
	if (head->next == NULL) //目前还是空链表
	{
		s->next = head->next;//即s->next=NULL;
		head->next = s;
	}
	else
	{
		while ((s->power > p1->power) && (p1->next != NULL))
		{   //查找插入位置，p2指向p1的前驱
			p2 = p1;
			p1 = p1->next;
		}
		if (s->power <= p1->power)
		{//while循环的结束条件有两个，需要判断是由哪个条件退出循环
		 //这是由while第一个条件退出循环，因此可插在p1结点之前
			p2->next = s;
			s->next = p1;
		}
		else
		{//由while循环条件的第二个条件退出循环，因此s->num最大，要插在最后
			p1->next = s;
			s->next = NULL;
		}
	}
}

//插入法对链表排序
void insertSort(ListNode* head)
{
	ListNode* p, * s;
	p = head->next;
	head->next = NULL;
	while (p)
	{
		s = p;
		p = p->next;
		insertNodeInOrder(head, s);
	}
}

int main() {
	int op;
	cin >> op;
	int n1,n2;
	cin >> n1;
	int arr1[20000];
	int arr2[20000];
	for (int i = 0; i < n1; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n1; i++) {
		cin >> arr2[i];
	}
	ListNode* A = createByArray(arr1,arr2,n1);
	cin >> n2;
	int arr3[20000];
	int arr4[20000];
	for (int i = 0; i < n2; i++) {
		cin >> arr3[i];
	}
	for (int i = 0; i < n2; i++) {
		cin >> arr4[i];
	}
	ListNode* B = createByArray(arr3, arr4, n2);
	displayLink(A);
	displayLink(B);

	fun(A, B, op);
	insertSort(A);
	displayLink(A);

	return 0;
}