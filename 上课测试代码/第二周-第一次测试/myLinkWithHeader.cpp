#include <iostream>
using namespace std;
#include "myLinkWithHeader.h"

//从键盘读入数据创建链表，新结点插入到尾部
ListNode* createByTail()
{
    ListNode* head;
    ListNode* p1, * p2;
    int num;
    cin >> num;
    head = new ListNode;
    head->next = NULL;//head指向头结点，此时为空链表
    p2 = head;
    while (num != 0)    //num为0，意味着用户输入结束
    {
        p1 = new ListNode;
        p1->num = num;
        p2->next = p1;
        p2 = p1;   //p2始终指向最后一个结点（即尾指针）
        cin >> num;
    }
    p2->next = NULL;  //切记：最后一个结点的next赋值为NULL
    return head;
}
//从键盘读入数据创建链表，新结点插入到头部
ListNode* createByHead()
{
    ListNode* head, * p1;
    int num;
    cin >> num;
    head = new ListNode;
    head->next = NULL;//head指向头结点，此时为空链表
    while (num != 0)
    {
        p1 = new ListNode;
        p1->num = num;
        p1->next = head->next;
        head->next = p1;
        cin >> num;
    }
    return head;
}
//根据数组arr创建链表，新结点插入到尾部
ListNode* createByArray(int arr[], int n)
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
        p->num = arr[i];
        r->next = p;
        r = p;
    }
    r->next = NULL; //切记：最后一个结点的next赋值为NULL
    return head;
}

//输出链表中的信息（num）
void  displayLink(ListNode* head)
{
    ListNode* p;
    p = head->next;
    cout << "head-->";
    while (p != NULL)
    {
        cout << p->num << "-->";
        p = p->next;
    }
    cout << "tail\n";
}
void  printList(ListNode* head)
{
    ListNode* p = head->next;
    while (p != NULL)
    {
        cout << p->num << endl;
        p = p->next;
    }
}

//获得链表的长度（结点数目）
int  getLength(ListNode* head)
{
    ListNode* p = head->next;
    int k = 0;
    while (p)  //while(p!=NULL)可以写成while(p)
    {
        k++;   //这里处理每一个结点时，只是进行累加
        p = p->next;
    }
    return k;
}
//根据传入的num查找结点，返回指针指向该结点
//若未找到，则返回NULL
ListNode* Locate(ListNode* head, int num)
{
    ListNode* p;
    p = head->next;
    while (p)
    {
        if (p->num == num)  break;
        p = p->next;
    }
    return p;
}
//删除链表中p指针指向的结点。
void deleteNode(ListNode* head, ListNode* p)
{
    ListNode* q;
    q = head;
    while (q->next != p)
        q = q->next;
    q->next = p->next;
    delete p;
}

//删除链表中学号为num的学生。由于学号不重复，因此本函数最多只删除一个结点
void deleteNode(ListNode* head, int num)
{
    ListNode* p1, * p2;
    if (head->next == NULL)
    {
        cout << "NULL list";
        return;
    }
    p2 = head;
    p1 = head->next;
    while (num != p1->num && p1->next != NULL)
    {//遍历查找满足条件的结点
        p2 = p1;
        p1 = p1->next;
    }
    if (num == p1->num)
    {//找到了满足条件的结点
        p2->next = p1->next;
        delete p1;
    }
    else //没找到满足条件的结点
        cout << "not been found!";
}
//逆置单链表
void invertLink(ListNode* head)
{
    ListNode* p, * s;
    p = head->next;
    head->next = NULL;
    while (p)
    {
        s = p;
        p = p->next;
        s->next = head->next;
        head->next = s;
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
        while ((s->num > p1->num) && (p1->next != NULL))
        {   //查找插入位置，p2指向p1的前驱
            p2 = p1;
            p1 = p1->next;
        }
        if (s->num <= p1->num)
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
//将s结点插到p结点的前面
void insertNode(ListNode* head, ListNode* p, ListNode* s)
{
    ListNode* q;
    q = head;
    while (q->next != p)
        q = q->next;
    q->next = s;
    s->next = p;
}
