#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    ListNode* next;
    int val;
    bool last = false;
    ListNode(int value) {
        val = value;
        next = nullptr;
    }
};
struct CycleList {
    int n;
    int N = 2;
    ListNode* head;
    void add(int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
        if(n >= N) {
            ListNode* cur = head;
            int size = N;
            while(size > 1) {
                cur = cur->next;
                size--;
            }
            cur->next = head;
            n = N;
            return ;
        }
        n++;
    }
    void printList() {
        int size = n;
        ListNode* cur = head;
        while(size > 0) {
            cout<<cur->val<<endl;
            cur = cur->next;
            size--;
        }
    }
};

int main()
{
    CycleList* cyc = new CycleList();
    ListNode* h = new ListNode(2);
    cyc->head = h;
    cyc->head->next = cyc->head;
    cyc->n = 1;
    cyc->add(3);cyc->add(4);cyc->add(5);cyc->add(6);
    cyc->printList();
   return 0;
}