#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 递归
TreeNode* pre = nullptr;
bool inOrder(TreeNode* cur) {
    if(cur == nullptr) return true;
    if(!inOrder(cur->left)) return false;
    if(pre != nullptr && cur->val <= pre->val) return false;
    pre = cur;
    return inOrder(cur->right);
}
bool isValidBST(TreeNode* root) {
    if(root == nullptr) return true;
    if(root->left == nullptr && root->right == nullptr) return true;
    return inOrder(root);
}
//中序遍历 使用栈
bool isValidBST(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* cur = root;
    TreeNode* pre = nullptr;
    while(!stk.empty() || cur != nullptr) {
        if(cur) {
            stk.push(cur);
            cur = cur->left;
        } else {
            cur = stk.top();
            stk.pop();
            if(pre != nullptr && pre->val >= cur->val)
                return false;
            pre = cur;
            cur = cur->right;
        }
    }
    return true;
}