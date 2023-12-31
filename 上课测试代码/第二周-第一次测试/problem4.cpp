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

        cin>>p1->num;

    }

    p2->next = NULL;  //切记：最后一个结点的next赋值为NULL

    return head;

}



//输出链表中的信息（num）

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



struct student* insertNodeInOrder(struct student* head, struct student* stu)

{

    struct student* p0, * p1, * p2;

    p1 = head;

    p0 = stu;

    if (head == NULL) //目前还是空链表

    {

        p0->next = head;

        head = p0;

    }

    else

    {

        while ((p0->num > p1->num) && (p1->next != NULL))

        {//查找插入位置，p2指向p1的前驱

            p2 = p1;

            p1 = p1->next;

        }

        //while循环的结束条件有两个，下面需要判断是由哪个条件退出循环

        if (p0->num <= p1->num)

        {//由while循环条件的第一个条件退出循环，因此可插在p1结点之前

            if (head == p1)     head = p0;

            else   p2->next = p0;

            p0->next = p1;

        }

        else

        {//由while循环条件的第二个条件退出循环，因此p0->num最大，要插在最后

            p1->next = p0;

            p0->next = NULL;

        }

    }

    return head;

}



struct student* sort(struct student* head)

{

    struct student* p, * s;

    p = head;

    head = NULL;

    while (p)

    {

        s = p;

        p = p->next;

        head = insertNodeInOrder(head, s);

    }

    return head;

}



struct student* merge(struct student* LA, struct student* LB)

{

    struct student* p, * s;

    p = LB;

    while (p)

    {

        s = p;

        p = p->next;

        LA = insertNodeInOrder(LA, s);

    }

    return LA;

}



struct student* subtract(struct student* LA, struct student* LB)

{

    struct student* q, * p = LB;

    struct student* pre = NULL;//pre指向q的前驱，所以最开始赋为NULL

    while (p != NULL) //对LB链表遍历

    {

        q = LA;

        while (q != NULL && q->num != p->num)
        {

            pre = q;

            q = q->next; //在LA中查找是否有元素与p->num相同

        }

        if (q != NULL) //找到了相同的元素，则删除q所指向结点

        {

            if (q == LA) //如果删除第一个结点

            {

                LA = LA->next;

                free(q);

            }

            else

            {

                pre->next = q->next;

                free(q);

            }

        }

        p = p->next;

    }

    return LA;

}



void purge(struct student* head)

{

    struct student* p, * q;

    if (head == NULL || head->next == NULL)

        return;

    p = head;

    while (p->next != NULL)

    {

        if (p->num == p->next->num)

        {

            q = p->next;

            p->next = q->next;

            free(q);

        }

        else

        {

            p = p->next;

        }

    }

}



struct student* fun(struct student* L1, struct student* L2) //L1进行插入，删除，都无头结点

{

    /*******************************编写本函数************************************/
    bool flag ;
    student* p1, * p2;
    p2 = L2;
    while (p2 != NULL)
    {
        flag = false;   //不存在
        p1 = L1;
        while (p1 != NULL) {
            if (p1->num == p2->num) {
                flag = true;    //存在
                break;
            }
            p1 = p1->next;
        }
        student* temp;
        temp = p1;
        if (flag == true) { //要进行删除
            student* q;
            if (temp == L1) //第一个结点
            {
                L1 = temp->next;
            }
            else {  //非首结点
                q = L1;
                while (q->next != temp) {
                    q = q->next;
                }
                q->next = temp->next;
            }
            delete temp;
        }
        else {  //要进行插入
            student* node;
            node= (struct student*)malloc(sizeof(struct student));
            node->num = p2->num;
            L1 = insertNodeInOrder(L1, node);
        }
        p2 = p2->next;
    }
    return L1;
}



int main()

{

    struct student* headA, * headB, * headC, * headD;

    int i, n;

    while (scanf("%d", &n) != EOF)

    {

        i = 0;

        while (i < n)

        {

            headA = createByTail();//创建链表A

            headB = createByTail();//创建链表B

            headC = createByTail();//创建链表C

            headD = createByTail();//创建链表D

            headA = sort(headA);//链表A排序

            headB = sort(headB);//链表B排序

            headC = sort(headC);//链表C排序

            headD = sort(headD);//链表D排序



            headA = merge(headA, headB);//将链表B合并到链表A中

            purge(headA);//删除链表A中重复元素

            headA = subtract(headA, headC);//从链表A中减去链表C中元素

            headA = fun(headA, headD);//对链表A和链表D调用fun函数

            displayLink(headA);//输出链表A中的元素

            i++;

        }

    }

    return 0;

}