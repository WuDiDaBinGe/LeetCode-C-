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