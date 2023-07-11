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

ListNode* findtail(ListNode* head)  //寻找链表的尾结点
{
    ListNode* tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    return tail;
}

class Solution {

public:

    ListNode* oddEvenList(ListNode* head) {

        //填充本函数完成功能  
        if (!head || !head->next || !head->next->next)
            return head;
        ListNode* tail = findtail(head);    //尾结点
        ListNode* q = tail;
        ListNode* tmpre = head;   //工作结点
        ListNode* tmp = head->next;
        while (tmpre != tail&& tmp!=tail) {
            tmpre->next = tmp->next;
            tmp->next = q->next;
            q->next = tmp;
            q = q->next;
            tmpre = tmpre->next;
            tmp = tmpre->next;
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

    head = Solution().oddEvenList(head);

    displayLink(head);

    return 0;

}

