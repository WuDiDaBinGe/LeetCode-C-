#include<bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == nullptr) return true;
        // 找到链表的一半节点 翻转前半部链表 跟后半部链表作比较
        ListNode* cur = new ListNode(-1);
        ListNode* fast = head, *slow = head;
        ListNode* nextp;
        for(; fast && fast->next;) {
            fast = fast->next->next;
            nextp = slow->next;
            slow->next = cur->next;
            cur->next = slow;
            slow = nextp;
        }
        //fast判断节点数目为奇数还是偶数
        ListNode* back;
        if(fast == nullptr) {
            back = slow;
        } else {
            back = slow->next;
        }
        cur = cur->next;
        while(cur && back) {
            if(cur->val == back->val) {
                cur = cur->next;
                back = back->next;
            } else{
                return false;
            }
        }
        return true;
    }
};