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

        //��䱾������ɹ���  
        //������ʱͷ���
        ListNode* tmphead = new ListNode(0,head);
        //map�洢��Ӧ�Ľ�����ǰ׺��
        map<int, ListNode*>last;
        int sum = 0;
        ListNode* tmp = tmphead;
        //��һ�α�������Ӧ������ǰ׺��������
        while (tmp)
        {
            sum += tmp->val;
            last[sum] = tmp;
            tmp = tmp->next;
        }
        //�ڶ��α�����ǰ׺����ͬ�Ľ��֮��Ľ�����ɾ��
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