#include<iostream>
#include<algorithm>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
    将链表尾节点指针指向头节点，形成一个环
    再从len-k处断开即得到移位之后的链表
*/
ListNode* rotateRight(ListNode* head, int k) {
    if(head == nullptr) return head;
    if(k==0) return head;
    int len =1;
    ListNode* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
        len++;
    }
    cur->next = head;
    // 保证k < len
    k = k % len;
    k = len - k;
    while (head!=nullptr&&k>1) {
        head = head->next;
        k--;
    }
    cur = head->next;
    head->next = nullptr;
    return cur;
}