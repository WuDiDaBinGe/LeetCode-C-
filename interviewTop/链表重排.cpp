#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* prev) {
        if(head == nullptr) return prev;
        ListNode* cur = reverse(head->next, head);
        head->next = prev;
        return cur;
    }
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        ListNode *dump = new ListNode(-1, head);
        ListNode* slow = dump, *fast = dump;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //2. 分割
        fast = slow->next;
        ListNode* back = reverse(fast, nullptr);
        slow->next = nullptr;
        //3. 组合
        ListNode* cur = head;
        while (cur && back) {
            ListNode* f1 = back->next;
            ListNode* h1 = cur->next;
            back->next = cur->next;
            cur->next = back;
            cur = h1;
            back = f1;
        }
        return ;
    }
};
int main(){
    return 0;
}