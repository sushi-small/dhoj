#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include<iostream>

using namespace std;



struct ListNode

{

    int val;

    ListNode* next;

    ListNode() : val(0), next(NULL) {}

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

ListNode* midNode(ListNode* head,ListNode* tail)   //通过快慢结点来寻找中间结点
{
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != tail) {
        slow = slow->next;
        fast = fast->next;
        if (fast != tail) {
            fast = fast->next;
        }
    }
    return slow;
}

class Solution {

public:

    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode* tmphead = new ListNode;
        ListNode* p = head1;
        ListNode* q = head2;
        ListNode* tmp = tmphead;
        while (p && q)
        {
            if (p->val <= q->val)
            {
                tmp->next = p;
                p = p->next;
            }
            else
            {
                tmp->next = q;
                q = q->next;
            }
            tmp = tmp->next;
        }

        if (p) {
            tmp->next = p;
        }
        else if (q) {
            tmp->next = q;
        }

        return tmphead->next;
    }

    ListNode* sortList(ListNode* head)

    {

        //填充本函数完成功能
        return sortList(head,NULL);

    }

    ListNode* sortList(ListNode* head, ListNode* tail)
    {
        if (!head)
        {
            return head;
        }
        if (head->next == tail)
        {
            head->next = NULL;
            return head;
        }
        ListNode* mid = midNode(head,tail);
        return merge(sortList(head,mid),sortList(mid,tail));
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

    ListNode* head = createByTail();

    head = Solution().sortList(head);

    displayLink(head);

    return 0;

}