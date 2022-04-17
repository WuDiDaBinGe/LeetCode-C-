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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* res_link=new ListNode(-1);
    ListNode* p1 = l1,*p2 = l2;
    while (p1!=nullptr||p2!=nullptr) {
        int value_a = p1==nullptr?0:p1->val;
        int value_b = p2==nullptr?0:p2->val;
        int value = (value_a+value_b+carry)%10;
        carry = (value_a+value_b+carry)/10;;
        res_link->next = new ListNode(value);
        res_link=res_link->next;
        p1 = p1==nullptr?nullptr:p1->next;
        p2 = p2==nullptr?nullptr:p2->next;
    }
    if (carry>0) {
        res_link->next = new ListNode(carry);
        res_link = res_link->next;
    }
    return res_link;
}
int main() {
    return 0;
}