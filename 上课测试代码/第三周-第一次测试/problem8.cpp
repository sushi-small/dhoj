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

    vector<int> nextLargerNodes(ListNode* head) {

        //填充本函数完成功能
        vector<int> res;
        if (!head || !head->next)       //无结点或只有一个结点的情况
        {
            res.push_back(0);
            return res;
        }
        ListNode* tmp=head;
        while (tmp) //对每个结点进行填充
        {
            ListNode* tmph = tmp->next;
            while (tmph)    //遍历其后的结点有没有比此结点值大的
            {
                if (tmph->val > tmp->val)   //有则填充
                {
                    res.push_back(tmph->val);
                    break;
                }
                tmph = tmph->next;
            }
            if(!tmph)   //没有则填充0
                res.push_back(0);
            tmp = tmp->next;
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



int main()

{

    ListNode* head = createByTail();

    vector<int> res = Solution().nextLargerNodes(head);

    for (int i = 0; i < res.size(); i++)

    {

        if (i > 0) cout << " ";

        cout << res[i];

    }

    cout << endl;

    return 0;

}