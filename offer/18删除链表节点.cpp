#include<iostream>
#include<string>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* pre = new ListNode(-1), *cur = head;
        pre->next = head;
        ListNode* temp = pre;
        if(head == nullptr) return head;
        while(cur != nullptr && cur->val != val) {
            pre = cur;
            cur = cur->next;
        }
        // 删除
        pre->next = cur->next;
        cur->next = nullptr;
        // delete(cur);
        return temp->next;
    }
};