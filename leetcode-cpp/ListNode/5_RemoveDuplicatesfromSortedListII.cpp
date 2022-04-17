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
    递归思想
*/
ListNode* deleteDuplicates(ListNode* head) {
    if(head==nullptr||head->next==nullptr) return head;
    ListNode* p = head->next;
    // 如果上一个元素和下一个元素有重复
    if (head->val==p->val) {
        // 删除下面重复的所有元素
        while (p!=nullptr && p->val ==head->val) {
            ListNode* temp=p;
            p = p->next;
            delete temp;
        }
        // 删除重复的头元素
        delete head;
        return deleteDuplicates(p);
    }
    // 若head元素下面无重复 处理他的下一个元素
    else {
        head->next = deleteDuplicates(head->next);
        return head;
    }
}
/*
    遍历思想:
    先定住一个元素，然后删除后面与它重复的元素，再删除该元素。
    011223445
*/
ListNode* deleteDuplicates2(ListNode* head) {
    if(head==nullptr||head->next==nullptr) return head;
    ListNode* dump = new ListNode(200);
    ListNode* pre = dump;
    pre->next = head;
    ListNode* cur = head;
    while (cur!=nullptr) {
        bool delDup = false;
        while (cur->next!=nullptr&&cur->val == cur->next->val) {
            ListNode* temp = cur;
            delDup = true;
            cur = cur->next;
            delete temp;
        }
        // 删除最后一个元素
        if (delDup) {
            ListNode* temp = cur;
            cur = cur->next;
            delete temp; 
            continue;
        }
        pre->next = cur;
        pre = pre->next;
        cur = cur->next;
    }
    pre->next = nullptr;
    return dump->next;
    
}
int main() {
    return 0;
}