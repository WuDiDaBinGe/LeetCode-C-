#include<bits/stdc++.h>
using namespace std;
struct TreeLinkNode {
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode* next;
    int val;
    TreeLinkNode(int x):val(x), right(nullptr),left(nullptr), next(nullptr){};
};
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        TreeLinkNode* root=pNode;
        while(root->next) root = root->next;

        // 有 右孩子
        if(pNode->right != nullptr) {
            TreeLinkNode* pnext = pNode->right;
            while(pnext->left){
                pnext = pnext->left;
            }
            return pnext;
        } else{
            if(pNode->next == nullptr) return nullptr;
            // 无右孩子 是左孩子
            if(pNode->next->left == pNode) {
                return pNode->next;
            }
            // 无右孩子 自己是右孩子
            else {
                TreeLinkNode* pnext = pNode->next;
                while(pnext->next && pnext->next->right == pnext){
                    pnext = pnext->next;
                }
                return pnext;
            }
        }

    }
};
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution1 {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(pNode == nullptr) return nullptr;
        if(pNode->right != nullptr) {
            TreeLinkNode* cur = pNode->right;
            while(cur->left) cur = cur->left;
            return cur;
        }
        else {
            // 根节点
            if(pNode->next == nullptr) return nullptr;
            // 左孩子 当前节点是父亲节点的左孩子
            if(pNode->next->left == pNode) return pNode->next;
            else {
                while(pNode->next != nullptr && pNode->next->left != pNode) pNode = pNode->next;
                return pNode->next;
            }
        }
    }
};