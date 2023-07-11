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

int ListLength(ListNode* head)
{
    int num = 0;
    ListNode* tmp=head;
    while (tmp)
    {
        num++;
        tmp = tmp->next;
    }
    return num;
}

class Solution

{

public:

    vector<ListNode*> splitListToParts(ListNode* root, int k)

    {

        //填充本函数完成功能  
        vector<ListNode*> res;
        int length = ListLength(root);
        int len = length / k;   //每一个链表的基础长度
        int len_remainder = length % k; //需要添加的结点的链表数
        ListNode* tmp = root;   //工作结点
        int num = 1;    //统计当前在进行第num个链表的创建
        while (k != 0)
        {
            ListNode* head=new ListNode;
            head->next = NULL;
            ListNode* h = head;
            int i = len;
            while (i != 0)
            {
                h->next = tmp;
                tmp = tmp->next;
                h = h->next;
                h->next = NULL;
                i--;
            }
            if (num <= len_remainder)
            {
                h->next = tmp;
                tmp = tmp->next;
                h = h->next;
                h->next = NULL;
            }
            res.push_back(head->next);
            k--;
            num++;
        }
        return res;
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

void  display(vector<ListNode*> lnVec)

{

    for (int i = 0; i < lnVec.size(); i++)

    {

        ListNode* p;

        p = lnVec[i];

        cout << "head-->";

        while (p != NULL)

        {

            cout << p->val << "-->";

            p = p->next;

        }

        cout << "tail\n";

    }

}

int main()

{

    vector<int> G;

    int k, data, res;

    ListNode* head = createByTail();

    cin >> k;

    vector<ListNode*> lnVec = Solution().splitListToParts(head, k);

    display(lnVec);

    return 0;

}