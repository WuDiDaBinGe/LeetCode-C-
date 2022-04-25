#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 递归函数的作用是判断以root为跟的树 能否找到target节点
bool search(TreeNode* root, TreeNode* target) {
    if(root == nullptr) return false;
    if(root->val == target->val) return true;
    return search(root->left, target) || search(root->right, target);
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(p->val == q->val) return p;
    if(root->val == p->val || root->val == q->val) return root;
    bool flag1 = search(root->left, p);
    bool flag4 = search(root->right, q);
    // 左右子树 存在 一个p 一个q
    if(flag1 && flag4) {return root;}
    bool flag2 = search(root->right, p);
    bool flag3 = search(root->left, q);
    if(flag2 && flag3) {return root;}
    TreeNode*  res;
    // 左子树存在p q
    if(flag1 && flag3)
        res = lowestCommonAncestor(root->left, p, q);
    // 右子树存在p q
    else if(flag2 && flag4)
        res = lowestCommonAncestor(root->right, p, q);
    return res;
}
// 题解的解法 因为二叉树上的每一个节点的的值都不同 不存在以下情况：p 不仅存在 左子树 也存在 右子树
TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 表示存在 p,q
    if(root == nullptr || root == p || root== q)
        return root;
    // 看左右子树 是否存在p 或者 q
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left == nullptr && right == nullptr)
        return nullptr;
    if(left == nullptr)
        return right;
    if(right == nullptr)
        return left;
    return root;
}
