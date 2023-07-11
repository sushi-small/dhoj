#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node

{

    int data;

    struct node* next;

};

//从键盘读入数据创建链表，新结点插入到尾部
struct node* createByTail(int n)
{
    struct node* head;
    struct node* p1, * p2;
    int num;
    num = 0;
    p1 = p2 = (struct node*)malloc(sizeof(struct node));
    head = NULL;  //首先置链表为空链表
    while (num!=n) {
        cin >> p1->data;
        if (num == 0)            //创建第一个结点
            head = p1;
        else
            p2->next = p1;
        p2 = p1;            //p2始终指向最后一个结点（即尾指针）
        p1 = (struct node*)malloc(sizeof(struct node)); //p1指向新结点      
        num++;
    }
    p2->next = NULL;  //最后一个结点的next赋值为NULL
    return head;
}

//输出链表中的信息（num）
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

//判断链表中是否有节点
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

//在链表中插入节点
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

//无头节点
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
        bool judge = is_exist_node(B,h->data);  //有是true，没有是false
        if (judge)
        {
            C=insertnode(C,h->data);
        }
        h = h->next;
    }
    displayLink(C);
    return 0;
}