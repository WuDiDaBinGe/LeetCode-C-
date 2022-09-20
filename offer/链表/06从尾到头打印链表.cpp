#include<bits/stdc++.h>
using namespace std;
// 递归
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        dfs(res, head);
        return res;
    }
    // digui
    void dfs(vector<int>& res, ListNode* head) {
        if(head == nullptr) return;
        dfs(res, head->next);
        res.push_back(head->val);
    }
};
// 栈

//