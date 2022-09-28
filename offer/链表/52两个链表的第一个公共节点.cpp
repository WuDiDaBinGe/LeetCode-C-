#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 判断两者的长度 然后长的先走 再返回共同的节点
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* cur1 = headA, *cur2 = headB;
    if(cur1 == nullptr || cur2 == nullptr) return nullptr;
    int len1 = 0, len2 = 0;
    while(cur1->next != nullptr) {
        cur1 = cur1->next;
        len1++;
    }
    while(cur2->next != nullptr) {
        cur2 = cur2->next;
        len2++;
    }
    if(cur1 != cur2) return nullptr;
    if(len1 < len2) {
        swap(len1, len2);
        cur1 = headB;
        cur2 = headA;
    } else {
        cur1 = headA; cur2 = headB;
    }
    while(len1 != len2) {
        cur1 = cur1->next;
        len1--;
    }
    while(cur1 != cur2) {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}
// 使用双指针
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* cur1 = headA, *cur2 = headB;
    while (cur1 != cur2) {
        cur1 = cur1 == nullptr ? headB : cur1->next;
        cur2 = cur2 == nullptr ? headA : cur2->next;
    }
    return cur1;       
}
int main() {
    return 0;
}