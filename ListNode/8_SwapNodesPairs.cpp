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
/*本题需要三个指针*/
ListNode* swapPairs(ListNode* head) {
    if(head == nullptr||head->next == nullptr) return head;
    ListNode dump(-1,head);
    for (ListNode* pre = &dump,*cur=pre->next,*next =cur->next;next!=nullptr;pre = cur,cur=cur->next,next=cur?cur->next:nullptr) {
        pre->next = next;
        cur->next = next->next;
        next->next = cur;
    }
    return dump.next;
}