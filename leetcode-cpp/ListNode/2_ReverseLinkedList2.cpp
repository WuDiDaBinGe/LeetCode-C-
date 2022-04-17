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
ListNode* reverseBetween(ListNode* head, int left, int right) {
     // 只翻转一个元素 相当于没翻转
     if (left==right) return head;
     ListNode* res = new ListNode(-1);
     ListNode* res_ = res;
     // 遍历left左边的元素，添加到链表
     for (int i=1;i<left&&head!=nullptr;i++) {
          res->next = new ListNode(head->val);
          res = res->next;
          head = head->next;
     }
     // 头插法 插入left-right之间的元素
     for (int i=left;i<=right&&head!=nullptr;i++) {
          res->next = new ListNode(head->val,res->next);
          head = head->next;
     }
     // 遍历到res末尾节点
     while (res->next != nullptr) {
          res = res->next;
     }
     // 遍历right右边的元素 添加到结果链表
     if (head!=nullptr) {
          res->next = head;
     }
     return res_->next;
}