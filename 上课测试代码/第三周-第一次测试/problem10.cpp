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

ListNode* findtail(ListNode* head)  //����β���
{
    ListNode* tmp=head;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    return tmp;
}

int ListLength(ListNode* head)  //�ж�����ĳ���
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

        //��䱾������ɹ���  
        ListNode* res = new ListNode(0, NULL);  //������
        ListNode* tmp = head;   //ԭ����Ĺ������
        int len = ListLength(head); //ԭ����ĳ���
        int circulate_num = 0;  //Ҫ�����������ѭ������
        while (circulate_num<len/k)
        {
            int count = 0;
            ListNode* tail = findtail(res); //Ѱ�Ҵ������β���
            while (count < k)
            {
                ListNode* tmphead = tmp;    //Ҫ���������Ľ��
                tmp = tmp->next;
                tmphead->next = tail->next;
                tail->next = tmphead;
                count++;
            }
            circulate_num++;
        }
        ListNode* tail = findtail(res); //Ѱ�Ҵ������β���
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