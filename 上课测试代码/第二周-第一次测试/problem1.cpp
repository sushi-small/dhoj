#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//��Ŀ1
struct ListNode
{
	int  num;
	struct ListNode* next;
};

//�Ӽ��̶������ݴ��������½����뵽β��
ListNode* createByTail(int n)
{
    ListNode* head;
    ListNode* p1, * p2;
    head = new ListNode;
    head->next = NULL;//headָ��ͷ��㣬��ʱΪ������
    p2 = head;
    int count=0;
    int num;
    while (count!=n)
    {
        cin >> num;
        p1 = new ListNode;
        p1->num = num;
        p2->next = p1;
        p2 = p1;   //p2ʼ��ָ�����һ����㣨��βָ�룩
        p2->next = NULL;  //�мǣ����һ������next��ֵΪNULL
        count++;
    }
    return head;
}

//���ݴ����num���ҽ�㣬����ָ��ָ��ý��
//��δ�ҵ����򷵻�NULL
int Locate(ListNode* head, int num)
{
    ListNode* p;
    p = head->next;
    int n = 0;
    while (p)
    {
        if (p->num == num)  break;
        p = p->next;
        n++;
    }
    if (!p)
    {
        return -1;
    }
    else
        return n;
}

int main()
{
    ListNode* h;
    int num;
    cin >> num;
    h = createByTail(num);
    int n;
    while (cin >> n)
    {
        if (Locate(h, n) == -1)
            cout << "no" << endl;
        else
            cout << Locate(h, n)+1 << endl;
    }
    return 0;
}