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
int result = INT_MIN;
int maxPathSum(TreeNode* root) {
    if(root->left == nullptr && root->right == nullptr) return root->val;
    dfs(root);
    return result;
}
// 树状dp
int dfs(TreeNode* root) {
    if(root == nullptr) return 0;
    int res = root->val;
    int left = dfs(root->left);
    int right = dfs(root->right);
    if(left > 0) res += left;
    if(right > 0) res += right;
    result = max(result, res);
    res = root->val;
    res = max(res, root->val + max(left, right));
    return res;
}