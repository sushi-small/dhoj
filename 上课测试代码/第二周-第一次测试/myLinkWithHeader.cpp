#include <iostream>
using namespace std;
#include "myLinkWithHeader.h"

//�Ӽ��̶������ݴ��������½����뵽β��
ListNode* createByTail()
{
    ListNode* head;
    ListNode* p1, * p2;
    int num;
    cin >> num;
    head = new ListNode;
    head->next = NULL;//headָ��ͷ��㣬��ʱΪ������
    p2 = head;
    while (num != 0)    //numΪ0����ζ���û��������
    {
        p1 = new ListNode;
        p1->num = num;
        p2->next = p1;
        p2 = p1;   //p2ʼ��ָ�����һ����㣨��βָ�룩
        cin >> num;
    }
    p2->next = NULL;  //�мǣ����һ������next��ֵΪNULL
    return head;
}
//�Ӽ��̶������ݴ��������½����뵽ͷ��
ListNode* createByHead()
{
    ListNode* head, * p1;
    int num;
    cin >> num;
    head = new ListNode;
    head->next = NULL;//headָ��ͷ��㣬��ʱΪ������
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
//��������arr���������½����뵽β��
ListNode* createByArray(int arr[], int n)
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
        p->num = arr[i];
        r->next = p;
        r = p;
    }
    r->next = NULL; //�мǣ����һ������next��ֵΪNULL
    return head;
}

//��������е���Ϣ��num��
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

//�������ĳ��ȣ������Ŀ��
int  getLength(ListNode* head)
{
    ListNode* p = head->next;
    int k = 0;
    while (p)  //while(p!=NULL)����д��while(p)
    {
        k++;   //���ﴦ��ÿһ�����ʱ��ֻ�ǽ����ۼ�
        p = p->next;
    }
    return k;
}
//���ݴ����num���ҽ�㣬����ָ��ָ��ý��
//��δ�ҵ����򷵻�NULL
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
//ɾ��������pָ��ָ��Ľ�㡣
void deleteNode(ListNode* head, ListNode* p)
{
    ListNode* q;
    q = head;
    while (q->next != p)
        q = q->next;
    q->next = p->next;
    delete p;
}

//ɾ��������ѧ��Ϊnum��ѧ��������ѧ�Ų��ظ�����˱��������ֻɾ��һ�����
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
    {//�����������������Ľ��
        p2 = p1;
        p1 = p1->next;
    }
    if (num == p1->num)
    {//�ҵ������������Ľ��
        p2->next = p1->next;
        delete p1;
    }
    else //û�ҵ����������Ľ��
        cout << "not been found!";
}
//���õ�����
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
        while ((s->num > p1->num) && (p1->next != NULL))
        {   //���Ҳ���λ�ã�p2ָ��p1��ǰ��
            p2 = p1;
            p1 = p1->next;
        }
        if (s->num <= p1->num)
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
//��s���嵽p����ǰ��
void insertNode(ListNode* head, ListNode* p, ListNode* s)
{
    ListNode* q;
    q = head;
    while (q->next != p)
        q = q->next;
    q->next = s;
    s->next = p;
}
