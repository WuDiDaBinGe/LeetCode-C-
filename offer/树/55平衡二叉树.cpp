#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 递归 O(n * n)  自顶向下
int maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
}
bool isBalanced(TreeNode* root) {
    if(root == nullptr) return true;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    int flag = isBalanced(root->left) && isBalanced(root->right);
    return abs(left - right) <= 1 && flag? true : false;
}
// 递归优化
int inOrder(TreeNode* root){
    if(root == nullptr) return 0;
    if(root->val < 0) return -root->val;
    int left = inOrder(root->left);
    int right = inOrder(root->right);
    root->val = -(max(left, right) + 1); 
    return -root->val;
}
bool IsBalanced_Solution(TreeNode* pRoot) {
    if(pRoot == nullptr) return true;
    int left = inOrder(pRoot->left);
    int right = inOrder(pRoot->right);
    return  abs(left - right) <= 1 && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}
// 优化 O(n) 自底向上
// 以root为根的子树是否为平衡二叉树，不是 返回 -1 否则返回树的深度
int maxDepth1(TreeNode* root) {
    if(root == nullptr) return 0;
    int left = maxDepth1(root->left);
    int right = maxDepth1(root->right);
    if(left == -1 || right == -1 || abs(left - right) > 1)
        return -1;
    else
        return max(left, right) + 1;
}
bool isBalanced1(TreeNode* root) {
    if(root == nullptr) return true;
    return maxDepth1(root) > -1;
}
int main() {
    return 0;
}