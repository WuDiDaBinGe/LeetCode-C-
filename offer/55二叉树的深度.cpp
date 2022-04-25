#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 递归
int maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
}
// 层序遍历
int maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while(!q.empty()) {
        int count = q.size();
        for(int i = 0; i < count; i++) {
            TreeNode* t = q.front(); q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        level++;
    }
    return level;
}