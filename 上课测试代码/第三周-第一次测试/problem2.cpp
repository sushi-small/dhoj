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

/*
ListNode* findTailpre(ListNode* head)
{
    ListNode* tmphead=head;
    while (tmphead->next->next)
    {
        tmphead = tmphead->next;
    }
    return tmphead;
}
*/

ListNode* findTail(ListNode* head)
{
    ListNode* tmphead = head;
    while (tmphead->next)
    {
        tmphead = tmphead->next;
    }
    return tmphead;
}

int LinkLength(ListNode* head)  //获取链表长度
{
    int num=0;
    ListNode* tmp=head;
    while (tmp)
    {
        num++;
        tmp = tmp->next;
    }
    return num;
}

ListNode* indexNode(ListNode* head, int index)
{
    int n=0;
    ListNode* tmp = head;
    while (n != index)
    {
        n++;
        tmp = tmp->next;
    }
    return tmp;
}

class Solution {

public:

    /*
    ListNode* rotateRight(ListNode* head, int k) {
        int num = 0;
        while (num != k)
        {
            ListNode* tmptailpre = findTailpre(head);
            ListNode* tmptail = tmptailpre->next;
            tmptailpre->next = tmptail->next;
            tmptail->next = head;
            head = tmptail;
            num++;
        }
        return head;
    }
    */
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head == NULL)
            return head;
        int n = LinkLength(head);
        //构成循环链表
        ListNode* tail = findTail(head);
        tail->next = head;
        
        k %= n;
        int num = n - k -1;
        if (num < 0)
            num += n;
        ListNode* tmpheadpre = indexNode(head, num);
        ListNode* tmphead = tmpheadpre->next;
        tmpheadpre->next = NULL;
        return tmphead;
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

//无头结点
int main()

{

    int k;

    ListNode* head = createByTail();

    cin >> k;

    head = Solution().rotateRight(head, k);

    displayLink(head);

    return 0;

}