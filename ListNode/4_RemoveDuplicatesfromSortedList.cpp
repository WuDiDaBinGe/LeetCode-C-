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
/*
    本题就是利用双指针的想法。
*/
ListNode* deleteDuplicates(ListNode* head) {
    ListNode dump(-200);
    ListNode* tail_dump = &dump;
    ListNode* pre_dump = &dump;
    for (ListNode* cur = head; cur!=nullptr; cur=cur->next) {
        if(tail_dump->val != cur->val){
            tail_dump->next = cur;
            tail_dump=tail_dump->next;
        }
    }
    // 将链表的末尾设置尾nullptr
    tail_dump->next=nullptr;
    return dump.next;
}
ListNode* deleteDuplicates1(ListNode* head) {
    if(head==nullptr) return head;
    for (ListNode *prev=head,*cur=head->next; cur; cur=prev->next) {
        if (prev->val == cur->val) {
            prev->next = cur->next;
            del cur;
        }   
        else {
            prev = cur;
        }
    }
    return head;
}