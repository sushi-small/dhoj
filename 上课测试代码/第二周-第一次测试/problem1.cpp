#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//题目1
struct ListNode
{
	int  num;
	struct ListNode* next;
};

//从键盘读入数据创建链表，新结点插入到尾部
ListNode* createByTail(int n)
{
    ListNode* head;
    ListNode* p1, * p2;
    head = new ListNode;
    head->next = NULL;//head指向头结点，此时为空链表
    p2 = head;
    int count=0;
    int num;
    while (count!=n)
    {
        cin >> num;
        p1 = new ListNode;
        p1->num = num;
        p2->next = p1;
        p2 = p1;   //p2始终指向最后一个结点（即尾指针）
        p2->next = NULL;  //切记：最后一个结点的next赋值为NULL
        count++;
    }
    return head;
}

//根据传入的num查找结点，返回指针指向该结点
//若未找到，则返回NULL
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