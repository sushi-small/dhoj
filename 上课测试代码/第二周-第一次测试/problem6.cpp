#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node

{

    int data;

    struct node* next;

};

//�Ӽ��̶������ݴ��������½����뵽β��
struct node* createByTail(int n)
{
    struct node* head;
    struct node* p1, * p2;
    int num;
    num = 0;
    p1 = p2 = (struct node*)malloc(sizeof(struct node));
    head = NULL;  //����������Ϊ������
    while (num!=n) {
        cin >> p1->data;
        if (num == 0)            //������һ�����
            head = p1;
        else
            p2->next = p1;
        p2 = p1;            //p2ʼ��ָ�����һ����㣨��βָ�룩
        p1 = (struct node*)malloc(sizeof(struct node)); //p1ָ���½��      
        num++;
    }
    p2->next = NULL;  //���һ������next��ֵΪNULL
    return head;
}

//��������е���Ϣ��num��
void  displayLink(struct node* head)
{
    struct node* p;
    p = head;
    printf("head-->");
    while (p != NULL)
    {
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("tail\n");
}

//�ж��������Ƿ��нڵ�
bool is_exist_node(struct node* head, int n)
{
    node* h = head;
    while (h) {
        if (h->data == n)
            return true;
        h = h->next;
    }
    return false;
}

//�������в���ڵ�
node* insertnode(struct node *head, int n)
{
    struct node* p1;
    p1 = (struct node*)malloc(sizeof(struct node));
    p1->data = n;
    struct node* h;
    h = head;
    if (!head)
    {
        p1->next = head;
        head = p1;
    }
    else
    {
        while (h->next != NULL)
        {
            h = h->next;
        }
        h->next = p1;
        p1->next = NULL;
    }
    return head;
}

//��ͷ�ڵ�
int main()
{
    node* A, * B, *C;
    int n;
    cin >> n;
    A = createByTail(n);
    cin >> n;
    B = createByTail(n);
    C = createByTail(0);
    node* h;
    h = A;
    while (h) {
        bool judge = is_exist_node(B,h->data);  //����true��û����false
        if (judge)
        {
            C=insertnode(C,h->data);
        }
        h = h->next;
    }
    displayLink(C);
    return 0;
}