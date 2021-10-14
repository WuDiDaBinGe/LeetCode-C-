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
/*头插法*/
ListNode* reverseList(ListNode* head) {
     ListNode* res = new ListNode(-1);
     // 头插法
     while (head!=nullptr) {
          res->next = new ListNode(head->val,res->next);
          head=head->next;
     }
     return res->next;
}
/*
     双指针
     需要记录下cur 的下一个节点，
     pre=cur
     cur=temp
*/
ListNode* reverseList1(ListNode* head) {
     if(head==nullptr||head->next==nullptr) return head;
     ListNode* pre = nullptr;
     ListNode* cur = head;
     while (cur!=nullptr) {
          ListNode* temp = cur->next;
          cur->next = pre;
          pre = cur;
          cur = temp;
     }
     return pre;
}
/*递归法*/