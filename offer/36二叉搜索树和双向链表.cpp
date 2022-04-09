#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node() {}
    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }
    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution {
public:
    // stack中序遍历处理
    Node* treeToDoublyList(Node* root) {
        stack<Node*> stk;
        Node* cur = root;
        Node* pre = nullptr;
        if(root == nullptr) return nullptr;
        while(cur != nullptr || !stk.empty()) {
            if(cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                // 处理 
                if(pre != nullptr) {
                    pre->right = cur;
                } 
                cur->left = pre;
                pre = cur;
                cur = cur->right;
            }
        }
        // 从最后一节开始 找到头结点
        Node* last = cur;
        while(cur->left != nullptr) {
            cur = cur->left;
        }
        last->right = cur;
        cur->left = last;
        return cur;
    }
    //递归版本：
    Node *listlast = nullptr;
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;
        inTravse(root);
        Node* cur = listlast;
        while(cur->left != nullptr) {
            cur = cur->left;
        }
        cur->left = listlast;
        listlast->right = cur;
        return cur;
    }
    void inTravse(Node* root) {
        if(root == nullptr) return;
        // 先遍历左子树 使其变为链表
        if(root->left != nullptr) {
            inTravse(root->left);
        }
        root->left = listlast;
        if(listlast != nullptr)
            listlast->right = root;
        listlast = root;
        if(root->right != nullptr) {
            inTravse(root->right);
        }
    }
};