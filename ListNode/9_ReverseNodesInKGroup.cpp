#include<iostream>
#include<algorithm>
#include<stack>
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
    和上一题即为k=2的情况
    本题的情况更为普遍
    只单纯的改变节点内部的值：
    使用一个栈保存节点，要数量达到K个才能弹出
*/
ListNode* reverseKGroup(ListNode* head, int k) {
    if(k==1) return head;
    stack<int> s;
    ListNode dump(-1,head);
    int temp=k;
    for (ListNode* pre = &dump, *cur=&dump;pre;k=temp) {
        while (cur!=nullptr&&k>0) {
            cur=cur->next;
            if (cur!=nullptr)
                s.push(cur->val);
            k--;
        }
        if (s.size()<temp) {
            return dump.next;
        }
        else {
            k=temp;
            while (k>0) {
                pre=pre->next;
                pre->val=s.top();
                s.pop();
                k--;
            }
        }
    }
    return dump.next;
}
/*
    改进做法：不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
    思路：将链表分解成翻转K个子区间的问题，
    要记录上一个子链表的最后一个元素，这样才能和下一个翻转的链表拼接。
*/
ListNode* reverseKGroup(ListNode* head, int k) {
    if (k==1||head==nullptr||head->next==nullptr) {
        return head;
    }
    ListNode dump(-1);
    int temp = k;
    ListNode* sub_last_node;
    ListNode* next;
    for (ListNode* pre=&dump, *begin=head,*end=begin;begin;k=temp,pre=sub_last_node,begin =next,end=begin) {
        while (end!=nullptr&&k>1) {
            end = end->next;
            k--;
        }
        if (end==nullptr){
            break;
        }
        // 记录子链表下一个元素
        next = end->next;
        // 记录子链表翻转后的倒数第一个元素
        sub_last_node = reverList(pre, begin, end);
    }
    return dump.next;
}
/*
    翻转子链表函数：head为子链表的前一个节点
    [begin,end]是要翻转的子链表。使用双指针翻转子链表。
*/
ListNode* reverList(ListNode*head,ListNode* begin,ListNode* end) {
    ListNode* pre=head;
    ListNode* cur=begin;
    ListNode* endnext = end->next;
    ListNode* next;
    // 遍历[begin,end]
    while (cur!=endnext) {
        next = cur->next;
        cur->next = pre;
        pre=cur;
        cur=next;
    }
    // 将子链表的前一个元素链接到翻转后子链表第一个元素
    head->next = end;
    // 翻转后链表的倒数第一个元素链接到子链表后的第一个元素
    begin->next = endnext;
    return begin;
}