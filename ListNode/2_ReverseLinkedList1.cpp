#include<iostream>
#include<algorithm>
#include<vector>

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverseList(ListNode* head) {
     ListNode* res = new ListNode(-1);
     // 头插法
     while (head!=nullptr) {
          res->next = new ListNode(head->val,res->next);
          head=head->next;
     }
     return res->next;
}