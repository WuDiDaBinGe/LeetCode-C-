#include<bits/stdc++.h>
using namespace std;
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(nullptr){}
};

ListNode* partition1(ListNode* start, ListNode* end) {
    if(start == nullptr || end == nullptr) return nullptr;
    int flag = start->val;
    ListNode* q = start->next;
    ListNode* p = start;
    while(q != end->next) {
        if(q->val < flag) {
            p = p->next;
            swap(p->val, q->val);
        }
        q = q->next;
    }
    swap(p->val, start->val);
    return p;
}
void quickSort(ListNode* start, ListNode* end) {
    if(start == end || start == nullptr) return;
    if(start->next == end) return;
    ListNode* border1 = partition1(start, end);
    quickSort(start, border1);
    quickSort(border1->next, end);
}
int main()
{
    ListNode* a1 = new ListNode(5);
    ListNode* a2 = new ListNode(7);
    ListNode* a3 = new ListNode(1);
    ListNode* a4 = new ListNode(2);
    ListNode* a5 = new ListNode(0);
    a1->next = a2; a2->next = a3;
    a3->next = a4; a4->next = a5;
    ListNode* cur = a1;
    while(cur != nullptr) {
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
    quickSort(a1, a5);
    cur = a1;
    while(cur != nullptr) {
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    return 0;
}