#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 头插法
ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head; 
    ListNode* dump = new ListNode(-1);
    ListNode* cur = head;
    while(cur) {
        ListNode* next = cur->next;
        cur->next = dump->next;
        dump->next = cur;
        cur = next;
    }
    return dump->next;
}
// 递归方法
ListNode* recur(ListNode* cur, ListNode* pre) {
    if(cur == nullptr) return pre;
    ListNode* res = recur(cur->next, cur);
    cur->next = pre;
    return res;
}
ListNode* reverseList2(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return nullptr;
    return recur(head, nullptr);
}