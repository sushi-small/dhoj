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
//�Ӽ��̶������ݴ��������½����뵽β��
struct student* createByTail()
{
    struct student* head;
    struct student* p1, * p2;
    int n;
    n = 0;
    p1 = p2 = (struct student*)malloc(sizeof(struct student));
    cin>>p1->num;
    head = NULL;  //����������Ϊ������
    while (p1->num != -1)    //numΪ-1����ζ���û��������
    {
        n = n + 1;
        if (n == 1)            //������һ�����
            head = p1;
        else
            p2->next = p1;
        p2 = p1;            //p2ʼ��ָ�����һ����㣨��βָ�룩
        p1 = (struct student*)malloc(sizeof(struct student)); //p1ָ���½��
        cin >> p1->num;
    }
    p2->next = NULL;  //���һ������next��ֵΪNULL
    return head;
}
//��������е���Ϣ��num��
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
//�������е�index������sָ����ָ��Ľ�㡣index��1��ʼ��
//���ڿ��ܲ��ڵ�һ����㣬���Ժ�������ͷָ�����������
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

//�������е�index������sָ����ָ��Ľ�㡣index��1��ʼ��
//���ڿ��ܲ��ڵ�һ����㣬���Ժ�������ͷָ�����������
struct student* insertNode(struct student* head, struct student* s, int index)
{
    struct student* p;
    p = head;
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }

    if (index > len + 1 || index <= 0) {//��������
        return head;
    }
    else {//���������� 
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