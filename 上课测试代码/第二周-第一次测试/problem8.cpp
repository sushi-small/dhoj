#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
	char num;
	int isGood;	//�ж��Ƿ�Ϊ���ˣ�isGoodΪ1����
	node* next;
};

struct node* create(int n, char num[]) //������ͷ����ѭ��������
{
	int i;
	node* current;	//��ǰ�����λ��ָ��
	node* tail;	//βָ��
	node* head;	//ͷָ��
	head = new node;	//�½�ͷ���
	head->next = NULL;
	current = head;	//��ָͷ
	tail = head;	//βָͷ
	for (i = 0; i < n; i++)	//����β�巨
	{
		node* p;
		p = new node;
		p->num = num[i];
		p->isGood = 1;
		p->next = current->next;
		current->next = p;
		current = p;
	}
	current->next = head;	//���ѭ��
	return head;
}

void arraylist(node* head, int n, int m)	//nΪ������mΪ����
{
	node* p = head->next;
	int count = 1;
	int len = n;
	while (len > 0) {
		if (count == m)//��������
		{
			if (p->isGood != -1)//�Ǻ���
			{
				p->isGood = -1;//�Ż���
				count = 1;
				len--;
			}
			p = p->next;
		}
		else if (count < m)
		{
			if (p->isGood != -1)//�Ǻ���
			{
				count++;
			}
			p = p->next;
		}

		if (p == head)//��֤ѭ������
			p = p->next;
	}
	//����������isGood���и�ֵ����

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
			cnt = 1;//���ע�������ʽΪ50��һ��
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
	int n, m;	//nΪ������mΪ����  n<=32767
	cin >> n >> m;
	int len = 2 * n;
	char arr[200000];
	for (int i = 0; i < len; i++)
	{
		arr[i] = 'G';	//Ŀ��������г�ʼ��
	}
	node* list = create(len,arr);	//�ܳ���Ϊlen
	arraylist(list, n, m);	//���ﱣ֤��������Ϊn������
	return 0;
}