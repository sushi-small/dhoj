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
	ListNode* r;	//rΪָ��β����ָ��
	r = head;
	ListNode* p;	//pΪָ����������ָ��
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
	//�󲢣������������la��
	ListNode* p, * q;
	if (!la->next) {
		la->next = lb->next;
		delete lb;	//lb��ͷ���ɾ��
		return;
	}
	p = lb;
	lb = lb->next;
	delete p;	//�ͷ�lb��ͷ���
	while (lb != NULL) {
		p = lb;
		lb = lb->next;
		q = la->next;
		while (q != NULL && q->power != p->power)	//�ҵ�p��q������ͬ��
			q = q->next;
		if (q == NULL)	//�Ҳ�����Ӧ��
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

	//ȥ������
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

//��sָ��Ľ����뵽���������У�����������num����
void insertNodeInOrder(ListNode* head, ListNode* s)
{
	ListNode* p1, * p2;
	p2 = head;
	p1 = head->next;
	if (head->next == NULL) //Ŀǰ���ǿ�����
	{
		s->next = head->next;//��s->next=NULL;
		head->next = s;
	}
	else
	{
		while ((s->power > p1->power) && (p1->next != NULL))
		{   //���Ҳ���λ�ã�p2ָ��p1��ǰ��
			p2 = p1;
			p1 = p1->next;
		}
		if (s->power <= p1->power)
		{//whileѭ���Ľ�����������������Ҫ�ж������ĸ������˳�ѭ��
		 //������while��һ�������˳�ѭ������˿ɲ���p1���֮ǰ
			p2->next = s;
			s->next = p1;
		}
		else
		{//��whileѭ�������ĵڶ��������˳�ѭ�������s->num���Ҫ�������
			p1->next = s;
			s->next = NULL;
		}
	}
}

//���뷨����������
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