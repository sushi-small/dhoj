#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct student
{
    int  num;
    struct student* next;
};
//从键盘读入数据创建链表，新结点插入到尾部
struct student* createByTail()
{
    struct student* head;
    struct student* p1, * p2;
    int n;
    n = 0;
    p1 = p2 = (struct student*)malloc(sizeof(struct student));
    cin>>p1->num;
    head = NULL;  //首先置链表为空链表
    while (p1->num != -1)    //num为-1，意味着用户输入结束
    {
        n = n + 1;
        if (n == 1)            //创建第一个结点
            head = p1;
        else
            p2->next = p1;
        p2 = p1;            //p2始终指向最后一个结点（即尾指针）
        p1 = (struct student*)malloc(sizeof(struct student)); //p1指向新结点
        cin >> p1->num;
    }
    p2->next = NULL;  //最后一个结点的next赋值为NULL
    return head;
}
//输出链表中的信息（num）
void  displayLink(struct student* head)
{
    struct student* p;
    p = head;
    cout<<"head-->";
    while (p != NULL)
    {
        cout<< p->num<<"-->";
        p = p->next;
    }
    cout<<"tail"<<endl;
}
//在链表中第index处插入s指针所指向的结点。index从1开始。
//由于可能插在第一个结点，所以函数返回头指针给主调函数
/*
student* insertNode(struct student* head, struct student* s, int index)
{
    int num = 1;
    student* h;
    h = head;
    if (index == 1)
    {
        s->next = head;
        head = s;
    }
    else
    {
        while (num != index-1)
        {
            h = h->next;
            num++;
        }
        s->next = h->next;
        h->next = s;
    }
    return head;
}
*/

//在链表中第index处插入s指针所指向的结点。index从1开始。
//由于可能插在第一个结点，所以函数返回头指针给主调函数
struct student* insertNode(struct student* head, struct student* s, int index)
{
    struct student* p;
    p = head;
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }

    if (index > len + 1 || index <= 0) {//超出长度
        return head;
    }
    else {//不超出长度 
        p = head;
        int tag = 1;
        while (tag != index) {
            p = p->next;
            tag++;
        }

        struct student* q;
        if (p == head) {
            s->next = head;
            head = s;
        }
        else {
            q = head;
            while (q->next != p) {
                q = q->next;
            }
            q->next = s;
            s->next = p;
        }

    }
    return head;

}

int main()
{
    struct student* head;
    int index, data;
    head = createByTail();
    while (cin>>index>>data)
    {
        struct student* s = (struct student*) malloc(sizeof(struct student));
        s->num = data;
        head = insertNode(head, s, index);
        displayLink(head);
    }
    return 0;
}