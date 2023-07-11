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

    ListNode* removeZeroSumSublists(ListNode* head) {

        //填充本函数完成功能  
        //创建临时头结点
        ListNode* tmphead = new ListNode(0,head);
        //map存储对应的结点和其前缀和
        map<int, ListNode*>last;
        int sum = 0;
        ListNode* tmp = tmphead;
        //第一次遍历将对应结点和其前缀和填充完毕
        while (tmp)
        {
            sum += tmp->val;
            last[sum] = tmp;
            tmp = tmp->next;
        }
        //第二次遍历将前缀和相同的结点之间的结点进行删除
        tmp = tmphead;
        sum = 0;
        while (tmp)
        {
            sum += tmp->val;
            tmp->next = last[sum]->next;
            tmp = tmp->next;
        }
        return tmphead->next;
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

    head = Solution().removeZeroSumSublists(head);

    displayLink(head);

    return 0;

}