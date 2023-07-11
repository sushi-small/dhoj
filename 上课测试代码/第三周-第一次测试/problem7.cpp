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

class Solution {

public:

    ListNode* swapPairs(ListNode* head) {

        //填充本函数完成功能  
        if (!head || !head->next)
            return head;
        //头结点的转换
        ListNode* tmp = head;
        ListNode* tm = head->next;
        tmp->next = tm->next;
        tm->next = tmp;
        head = tm;
        while (tmp->next&&tmp->next->next)
        {
            ListNode* tmpnode = tmp->next;
            tmp->next = tmpnode->next;
            tmpnode->next = tmpnode->next->next;
            tmp->next->next = tmpnode;
            tmp = tmpnode;
        }
        return head;
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

    head = Solution().swapPairs(head);

    displayLink(head);

    return 0;

}