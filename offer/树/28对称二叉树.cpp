#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};
bool isSymmetric(TreeNode* root) {
    if(root == nullptr) return true;
    return isSym(root->left, root->right);
}
bool isSym(TreeNode* a, TreeNode* b) {
    if(a == nullptr && b == nullptr) return true;
    if(a == nullptr || b == nullptr) return false;
    if(a->val != b->val) return false;
    return isSym(a->left, b->right) && isSym(a->right, b->left);
}
class Solution {
public:
    bool check(TreeNode *u, TreeNode *v) {
        queue <TreeNode*> q;
        q.push(u); q.push(v);
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left); 
            q.push(v->right);

            q.push(u->right); 
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};