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
int res = INT_MIN;
int diameterOfBinaryTree(TreeNode* root) {
    dfs(root);
    return res;
}
int dfs(TreeNode* root) {
    if(root == nullptr) return 0;
    int left_d = dfs(root->left);
    int right_d = dfs(root->right);
    res = max(res, left_d + right_d + 1);
    return max(left_d, right_d) + 1;
}