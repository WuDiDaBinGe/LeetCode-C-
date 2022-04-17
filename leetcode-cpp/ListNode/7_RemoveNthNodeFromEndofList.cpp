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
    两个指针，p 、q q走n步  p在和q一起走 
    当q走到末尾的时候 删除p即可
*/
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* q = head;
    ListNode* p = head;
    while (n>0) {
        q = q->next;
        n--;
    }
    // 遍历到了末尾 n == 链表长度 删除第一个元素
    if(q==nullptr) {
        return head->next;
    }
    while (q->next != nullptr) {
        q = q->next;
        p = p->next;
    }
    p->next = p->next->next;
    return head;
}
int main() {
    return 0;
}