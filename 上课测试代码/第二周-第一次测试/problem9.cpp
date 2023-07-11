#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//˫������Ľṹ 
typedef struct List {
	int data;			// 	������
	struct List* next;		//  ����ָ��
	struct List* front;		//  ��ǰ��ָ��
};

//����ͷ���
List* CreateList(int n)	//n��1��-1
{
	List* head = (List*)malloc(sizeof(List));
	head->next = head->front = NULL;
	head->data = n;
	return head;
}

//˫�����������-ͷ�巨
List* InsertList(List* head, int data)
{
	List* p1= (List*)malloc(sizeof(List));
	p1->next = p1->front = NULL;
	p1->data = data;
	int n = 0;
	if (!head->next) {
		head->next = p1;
		p1->front = head;
	}
	else {
		head->next->front = p1;
		p1->next = head->next;
		head->next = p1;
		p1->front = head;
	}
	return head;
}

//��������е���Ϣ
void displayList(List* head)
{
	int n = 0;
	List* tmphead = head;
	if (tmphead->next == NULL)
	{
		cout << 0;
		return;
	}
	while (tmphead != NULL)
	{
		if (n == 0) {
			if (tmphead->data==-1) {
				cout << "-";
			}
		}
		else if (n == 1) {
			if (tmphead->next == NULL) {
				cout << tmphead->data;
			}
			else {
				cout << tmphead->data<<",";
			}
		}
		else {
			if (tmphead->next == NULL) {
				int a = tmphead->data;
				cout << a / 1000 << a / 100 % 10 << a / 10 % 10 << a % 10;
			}
			else {
				int a = tmphead->data;
				cout << a / 1000 << a / 100 % 10 << a / 10 % 10 << a % 10 << ",";
			}
		}
		n++;
		tmphead = tmphead->next;
	}
	cout << endl;
}

//���������
int char_int(int a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a *= 10;
	}
	return a;
}

//��β���
List* tail(List* head)
{
	List* tmphead;
	tmphead = head;
	while (tmphead->next != NULL) {
		tmphead = tmphead->next;
	}
	return tmphead;
}

int getLength(List* head)
{
	List* p = head->next;
	int k = 0;
	while (p) {
		k++;
		p = p->next;
	}
	return k;
}

struct List* add(struct List* num1, struct List* num2) {

	struct List* head = new List;
	head->next = NULL;
	head->front = NULL;
	struct List* p = num1;
	struct List* q = num2;
	while (p->next)
		p = p->next;
	while (q->next)
		q = q->next;
	while (p != num1 && q != num2) {          //��β����ͷ�����мӱ���
		struct List* t = new List;
		struct List* o = head->next;
		t->data = num1->data * p->data + num2->data * q->data;

		head->next = t;
		t->front = head;
		t->next = o;
		if (o)
			o->front = t;

		p = p->front;
		q = q->front;
	}

	while (p != num1) {     //�����ںϲ��������û������Ľ�����ͷ������ķ���

		struct List* t = new List;
		struct List* o = head->next;

		t->data = num1->data * p->data;

		head->next = t;
		t->front = head;
		t->next = o;
		if (o)
			o->front = t;
		p = p->front;
	}

	while (q != num2) {

		struct List* t = new List;
		struct List* o = head->next;

		t->data = num2->data * q->data;

		head->next = t;
		t->front = head;
		t->next = o;
		if (o)
			o->front = t;
		q = q->front;
	}
	if (head->next->data > 0)    //�ж�����ȡֵ�����Ǹ�
		head->data = 1;
	else
		head->data = -1;

	p = head;
	while (p->next)
		p = p->next;
	q = p;

	while (p != head) {                 //�Խ�����д���

		if (p->data * head->data < 0) {  //������λ��һ��������λ��1
			if (head->data > 0) {
				p->data += 10000;
				p->front->data -= 1;
			}
			else {
				p->data -= 10000;
				p->front->data += 1;
			}
		}

		p = p->front;
	}
	p = head->next;
	while (p) {
		p->data = abs(p->data);
		p = p->next;
	}
	while (q != head->next) {          //���н�λ����
		if (q->data >= 10000) {
			q->data -= 10000;
			q->front->data += 1;
		}
		q = q->front;
	}

	if (q && q->data >= 10000) {

		struct List* t = new List;
		t->next = q;
		q->front = t;
		head->next = t;
		t->front = head;
		t->data = q->data / 10000;
		q->data = q->data % 10000;
	}

	p = head->next;  //��ǰ�߳���0ʱɾ���ý��
	while (p && p->data == 0) {
		p->front->next = p->next;

		if (p->next)
			p->next->front = p->front;
		p = p->next;
	}
	
	return head;
};

int main()
{
	char x[200000];
	char y[200000];
	cin >> x;
	cin >> y;
	int len_x = strlen(x);
	int len_y = strlen(y);
	//����xl
	List* xl;
	if (x[0] == '-')
	{
		xl = CreateList(-1);
	}
	else
		xl = CreateList(1);
	int i = len_x - 1;
	int j;
	if (x[0] == '-')
		j = 1;
	else
		j = 0;
	while (i >= j) {
		int n=0,num=0;
		while (num < 4 && i >= j)
		{
			n += char_int((int)x[i]-48,num);
			i--;
			num++;
		}
		xl = InsertList(xl,n);
	}
	displayList(xl);
	//����yl
	List* yl;
	if (y[0] == '-')
	{
		yl = CreateList(-1);
	}
	else
		yl = CreateList(1);
	i = len_y - 1;
	if (y[0] == '-')
		j = 1;
	else
		j = 0;
	while (i >= j) {
		int n = 0, num = 0;
		while (num < 4 && i >= j)
		{
			n += char_int((int)y[i] - 48, num);
			i--;
			num++;
		}
		yl = InsertList(yl, n);
	}
	displayList(yl);
	cout << endl;
	//���
	List* zl;
	zl = add(xl, yl);
	displayList(zl);
	return 0;
}

