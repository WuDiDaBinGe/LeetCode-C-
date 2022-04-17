#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 递归 O(n * n)
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
// 优化 O(n)
int maxDepth1(TreeNode* root) {
    if(root == nullptr) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    if(left == -1 || right == -1 || abs(left - right) > 1)
        return -1;
    else
        return max(left, right) + 1
}
bool isBalanced1(TreeNode* root) {
    if(root == nullptr) return true;
    return maxDepth1(root) > -1;
}
int main() {
    return 0;
}