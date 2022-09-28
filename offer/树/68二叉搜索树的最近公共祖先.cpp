#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 递归遍历
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(p->val > q->val) swap(p, q);
    if(p->val == q->val) return p;
    if(root->val == p->val || root->val == q->val || (root->val > p->val && root->val < q->val)) return root;
    else if(q->val < root->val) return lowestCommonAncestor(root->left, p, q);
    else return lowestCommonAncestor(root->right, p, q);
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(p->val == q->val) return p;
    if(root->val == p->val || root->val == q->val || (root->val > p->val && root->val < q->val)) return root;
    while(root) {
        if(root->val > q->val && root->val > p->val)
            root = root->left;
        else if(root->val < q->val && root->val < p->val)
            root = root->right;
        else
            break; 
    }
    return root;
}