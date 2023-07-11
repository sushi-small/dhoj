#include <stdio.h>
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

    p2->next = NULL;  //�мǣ����һ������next��ֵΪNULL

    return head;

}

//��������е���Ϣ��num��

void  displayLink(struct student* head)

{

    struct student* p;

    p = head;

    printf("head-->");

    while (p != NULL)

    {

        printf("%d-->", p->num);

        p = p->next;

    }

    printf("tail\n");

}

int LinkLength(student* head)
{
    int num = 0;
    student* s;
    s = head;
    while (s) {
        num++;
        s = s->next;
    }
    return num;
}

//ɾ�������е�index����㡣index��1��ʼ��

//���ڿ���ɾ����һ����㣬���Ժ�������ͷָ�����������

struct student* deleteNode(struct student* head, int index)
{
    int length = LinkLength(head);
    if (index > length||index<=0)
        return head;
    else {
        student* h;
        h = head;
        int count = 1;
        while (count != index) {
            count++;
            h = h->next;
        }
        student* q; //p��ǰ�����
        if (h == head) {    //���Ҫɾ�����ǵ�һ�����
            head = h->next;
        }
        else {
            q = head;
            while (q->next != h) {
                q = q->next;
            }
            q->next = h->next;
        }
        delete h;
    }
    return head;
}

int main()
{
    struct student* head;

    int index;

    head = createByTail();

    while (scanf_s("%d", &index) != -1)
    {

        head = deleteNode(head, index);

        displayLink(head);

    }
    return 0;
}