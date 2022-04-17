#include<iostream>
#include<algorithm>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/* 
    因为环一定是从链表尾链接过来的：使用操场追及问题
*/
ListNode *detectCycle(ListNode *head) {
    for (ListNode* fast=head,*slow=head;fast&&fast->next;) {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow) {
            ListNode* slow2=head;
            while (slow2 != slow) {
                slow =  slow->next;
                slow2 = slow2->next;
            }
            return slow2;
        }
    }
    return nullptr;
}