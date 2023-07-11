#include<stdio.h>

#include<stdlib.h>

#include <string.h>

#include<time.h>

#include<iostream>

#include<bits/stdc++.h>

using namespace std;
struct node

{

    char data;

    struct node* next;

};

struct node* create(char text[])

{

    int i;

    struct node* current;//当前插入位置指针

    struct node* tail;//尾指针

    struct node* head;//头指针

    head = (struct node*)malloc(sizeof(struct node));//头结点

    head->next = NULL;

    current = head;//当前位置指针指向头结点

    tail = head;//尾指针也指向头结点

    for (i = 0; i < strlen(text); i++)

    {

        if (text[i] == '[')

        {//当前位置指针回到最前面

            current = head;

        }

        else if (text[i] == ']')

        {//当前位置指针移到最后面

            current = tail;

        }

        else

        {//在当前位置指针后面插入结点

            struct node* p;

            p = (struct node*)malloc(sizeof(struct node));

            p->data = text[i];

            p->next = current->next;

            current->next = p;

            current = p;

            if (current->next == NULL) tail = current; //当前位置在最后面，则需要修改tail指针

        }

    }

    return head;

}

int count(struct node* head)

{

    //请在此输入你的代码，统计单词数目并返回



    //函数形参为链表头指针，注意，其中第一个结点是头结点

    int num = 0; //用于统计的变量
    bool flag=false;   //用于判断此时指的是字符(true)还是空格(false)
    node* h;
    h = head->next;
    while (h)
    {
        if (flag==false&&h->data != ' ')
        {
            flag = true;
            num++;
        }
        else if(flag==true&& h->data == ' ')
        {
            flag = false;
        }
        h = h->next;
    }
    return num;
}

int main()

{

    //freopen("input2.txt","r",stdin);

    //freopen("output2.txt", "w", stdout);

    char text[100005];

    struct node* head, * p;

    int num;

    while (gets_s(text) != NULL)

    {

        head = create(text);

        //for(p=head->next; p!=NULL; p=p->next)

        //    printf("%c",p->data);

        //printf("\n");

        num = count(head);

        printf("%d\n", num);

    }



    //printf("%.2f\n", (double)clock()/CLOCKS_PER_SEC);

    return 0;

}