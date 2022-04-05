#include<iostream>
#include<algorithm>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node* copyRandomList(Node* head) {
    if(head==nullptr) return nullptr;
    // a->b->c a->a'->b->b'->c->c'
    for (Node* cur = head; cur !=nullptr;) {
        Node* dupNode = new Node(cur->val);
        dupNode->next = cur->next;
        cur->next = dupNode;
        cur = dupNode->next;
    }
    // 将复制节点的random 指针 指向其原节点 随即指针指向元素的复制元素(即其下一个元素)
    for (Node* cur=head;cur!=nullptr;cur=cur->next->next) {
        if (cur->random==nullptr) {
            cur->next->random = nullptr;
        }
        else {
            cur->next->random = cur->random->next;
        }
    }
    // 拆分两个链表:这里要完全拆开
    Node* dump = new Node(-1);
    for (Node* cur = head, *new_cur = dump;cur!=nullptr;) {
        new_cur->next = cur->next;
        new_cur = new_cur->next;
        cur->next = cur->next->next;
        cur = cur->next;
    }
    return dump->next;
}