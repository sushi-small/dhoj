#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode

{

    int val;

    ListNode* next;

    ListNode() : val(0), next(NULL) {}

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

ListNode* findtail(ListNode* head)  //查找尾结点
{
    ListNode* tmp=head;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    return tmp;
}

int ListLength(ListNode* head)  //判断链表的长度
{
    int len = 0;
    ListNode* tmp = head;
    while (tmp)
    {
        len++;
        tmp = tmp->next;
    }
    return len;
}

class Solution {

public:

    ListNode* reverseKGroup(ListNode* head, int k) {

        //填充本函数完成功能  
        ListNode* res = new ListNode(0, NULL);  //答案链表
        ListNode* tmp = head;   //原链表的工作结点
        int len = ListLength(head); //原链表的长度
        int circulate_num = 0;  //要进行整体插入循环几次
        while (circulate_num<len/k)
        {
            int count = 0;
            ListNode* tail = findtail(res); //寻找答案链表的尾结点
            while (count < k)
            {
                ListNode* tmphead = tmp;    //要插入答案链表的结点
                tmp = tmp->next;
                tmphead->next = tail->next;
                tail->next = tmphead;
                count++;
            }
            circulate_num++;
        }
        ListNode* tail = findtail(res); //寻找答案链表的尾结点
        tail->next = tmp;
        return res->next;
    }
};

ListNode* createByTail()

{

    ListNode* head;

    ListNode* p1, * p2;

    int n = 0, num;

    int len;

    cin >> len;

    head = NULL;

    p2 = head;

    while (n<len && cin >> num)

    {

        p1 = new ListNode(num);

        n = n + 1;

        if (n == 1)

            head = p1;

        else

            p2->next = p1;

        p2 = p1;

    }

    return head;

}

void  displayLink(ListNode* head)

{

    ListNode* p;

    p = head;

    cout << "head-->";

    while (p != NULL)

    {

        cout << p->val << "-->";

        p = p->next;

    }

    cout << "tail\n";

}

int main()

{

    int k;

    ListNode* head = createByTail();

    cin >> k;

    head = Solution().reverseKGroup(head, k);

    displayLink(head);

    return 0;

}