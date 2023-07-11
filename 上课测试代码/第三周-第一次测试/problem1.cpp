#include<stdio.h>
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

int count(ListNode* head)   //计算链表中有多少个结点
{
    int num = 0;
    while (head)
    {
        num++;
        head = head->next;
    }
    return num;
}

ListNode* TailNode(ListNode* head)  //查找链表中的尾结点的前一个结点
{
    ListNode* tmp=head;
    while (tmp->next->next)
    {
        tmp = tmp->next;
    }
    return tmp;
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

class Solution

{

public:

    /*void reorderList(ListNode* head)
    {
        ListNode* tmp = head;
        int n = count(head);
        if (n == 3)
        {
            ListNode* tailpre = TailNode(head);
            ListNode* tail = tailpre->next;
            tailpre->next = tail->next;
            tail->next = tmp->next;
            tmp->next = tail;
        }
        else {
            int i;
            for (i = 0; i < n - 3; i++)
            {
                ListNode* tailpre = TailNode(head);
                ListNode* tail = tailpre->next;
                tailpre->next = tail->next;
                tail->next = tmp->next;
                tmp->next = tail;
                tmp = tmp->next->next;
            }
        }
    }
    */

    //快慢指针找到中间结点
    ListNode* findmid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    //将整个链表倒置
    ListNode* ReverList(ListNode* head)
    {
        ListNode* tmphead=new ListNode;
        tmphead->next = NULL;
        //采用头插法
        while (head) {
            ListNode* tmp = head;
            head = head->next;
            tmp->next = tmphead->next;
            tmphead->next = tmp;
        }
        //tmphead为临时头结点，因为题目中的链表是无头结点的，所以返回链表时将临时头结点去掉
        return tmphead->next;
    }

    //将两个链表合并
    ListNode* mergeList(ListNode* head1, ListNode* head2)
    {
        ListNode* tmphead=new ListNode;
        tmphead->next = NULL;
        ListNode* tail = tmphead;
        while (head1 && head2) {
            ListNode* p = head1;
            ListNode* q = head2;
            head1 = head1->next;
            head2 = head2->next;
            p->next = tail->next;
            tail->next = p;
            tail = tail->next;
            q->next = tail->next;
            tail->next = q;
            tail = tail->next;
        }
        while (head1)
        {
            ListNode* p = head1;
            head1 = head1->next;
            p->next = tail->next;
            tail->next = p;
            tail = tail->next;
        }
        return tmphead->next;
    }

    void reorderList(ListNode* head)
    {
        if (head)
        {
            ListNode* mid = findmid(head);
            ListNode* head1 = head;
            ListNode* head2 = mid->next;
            mid->next = NULL;
            head2 = ReverList(head2);
            head = mergeList(head1, head2);
        }

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




//无头结点
int main()

{

    ListNode* head = createByTail();

    Solution().reorderList(head);

    displayLink(head);

    return 0;

}