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
    从头遍历：
    创建两个链表头：将小于x的元素连接到left链表，将大于等于元素
    链接到right链表。
    最终再将两个列表合并
*/
ListNode* partition(ListNode* head, int x) {
    ListNode* left_dump = new  ListNode(-1);
    ListNode* right_dump= new  ListNode(-1);

    ListNode* left_cur = left_dump;
    ListNode* right_cur = right_dump;
    for (ListNode* cur = head; cur!= nullptr; cur = cur->next) {
        if (cur->val<x) {
            left_cur->next = cur;
            left_cur = left_cur->next;
        }
        else{
            right_cur->next = cur;
            right_cur = right_cur->next;
        }
    }
    // 两个链表合并操作
    left_cur->next = right_dump->next;
    right_cur->next = nullptr;
    return left_dump->next;
}