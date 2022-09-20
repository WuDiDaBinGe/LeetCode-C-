#include<bits/stdc++.h>
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
class Solution {
public:
    // 使用哈希表的方式
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hash; //key:旧节点 value:新节点
        if(head == nullptr) return nullptr;
        Node* root = new Node(head->val);
        hash[head] = root;
        Node* cur = head->next, *pre = root;
        // 构造顺序链表
        while(cur) {
            Node* t = new Node(cur->val);
            hash[cur] = t;
            pre->next = t;
            pre = t;
            cur = cur->next;
        }
        // 构造顺序链表结构的random指针
        cur = head, pre = root;
        while(cur) {
            pre->random = hash[cur->random];
            cur = cur->next;
            pre = pre->next;
        }
        return root;
    }
    // 使用不使用哈希表方式 使用
    /*  1. 复制节点插入到链表中 
        2. 更新复制节点的random节点
        3. 拆开两个链表
    */
    Node* copyRandomList(Node* head) {
        
    }
};
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(pHead==nullptr) return nullptr;
        RandomListNode* cur = pHead;
        // 1. insert new node
        while(cur){
            RandomListNode* node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        // 2. connect the Random
        RandomListNode *old = pHead, *res = pHead->next, *newp = pHead->next;
        while(old){
            newp->random = old->random == nullptr ? nullptr : old->random->next;
            if(old->next) old = old->next->next;
            if(newp->next) newp = newp->next->next;
        }
        old = pHead, newp = pHead->next;
        while(old){
            if(old->next) old->next = old->next->next;
            if(newp->next) newp->next = newp->next->next;
            old = old->next;
            newp = newp->next;
        }
        return res;
    }
};