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
ListNode* reversList(ListNode* head) {
    if(head==nullptr||head->next==nullptr) return head;
    ListNode* pre=nullptr;
    for (ListNode *cur=head;cur;pre=cur) {
        ListNode* temp=cur->next;
        cur->next = pre;
        cur=temp;
    }
    return pre;
}
/*
    使用快慢指针找到中间节点
    从中间节点断开，将后面的链表翻转
    合并两个子链表
*/
void reorderList(ListNode* head) {
    if(head==nullptr||head->next==nullptr||head->next->next==nullptr) return;
    ListNode* slow=head,*fast=head;
    while (fast&&fast->next) {
        fast=fast->next->next;
        slow=slow->next;
    }
    // slow为断开元素的前一个元素 翻转后面的链表
    fast = reversList(slow->next);
    //!!!!!一定要记得断开 否则会报错
    slow->next = nullptr;
    // 合并两个单链表
    for(ListNode* head1=head;head1&&fast;){
        ListNode *cur =fast;
        fast=fast->next;
        cur->next=head1->next;
        head1->next=cur;
        head1=head1->next->next;
    }
}

int main(){
    return 0;
}