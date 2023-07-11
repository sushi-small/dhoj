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

    int numComponents(ListNode* head, vector<int>& G) {
        //�����ݷ��뼯����
        set<int> set;
        for (int n : G)
        {
            set.emplace(n);
        }
        int res = 0;
        bool isexist = false;
        ListNode* tmp = head;
        //����
        while (tmp) {
            //ֵ�������г���
            if (set.count(tmp->val)) {
                //������еĵ�һ����
                if (!isexist) {
                    res++;
                    isexist = true;
                }
            }
            //δ���ֱ�־λ��ʼ��
            else
            {
                isexist = false;
            }
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

//����ͷ���
int main()

{

    vector<int> G;

    int m, data, res;

    ListNode* head = createByTail();

    cin >> m;

    for (int i = 0; i < m; i++)

    {

        cin >> data;

        G.push_back(data);

    }

    res = Solution().numComponents(head, G);

    cout << res << endl;

    return 0;

}