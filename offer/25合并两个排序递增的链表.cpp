#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 递推
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;
    if(l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
    ListNode* p1 = l1, *p2 = l2;
    ListNode* dump = new ListNode(-1);
    ListNode* p = dump;
    while(p1 != nullptr && p2 != nullptr) {
        if(p1->val <= p2->val) {
            dump->next = p1;
            dump = p1;
            p1 = p1->next;
        } else {
            dump->next = p2;
            dump = p2;
            p2 = p2->next;
        }
    }
    if(p1 != nullptr) {
        dump->next = p1;
    } 
    if(p2 != nullptr) {
        dump->next = p2;
    }
    return p->next;
}