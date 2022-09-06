#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int kthLargest(TreeNode* root, int k) {
    stack<TreeNode*> stk;
    if(root == nullptr) return -1;
    TreeNode* cur = root;
    while(cur != nullptr || !stk.empty()) {
        if(cur) {
            stk.push(cur);
            cur = cur->right;
        } else {
            cur = stk.top(); stk.pop();
            k--;
            if(k == 0) return cur->val;
            cur = cur->left;
        }
    }
    return -1;
}
int ak, res = 0;
int kthLargest(TreeNode* root, int k) {
    ak = k;
    inOrder(root);
    return res;
}
void inOrder(TreeNode* root) {
    if(root == nullptr) return;
    inOrder(root->right);
    if(ak == 0) return ;
    ak--;
    if(ak == 0) {
        res = root->val;
        return;
    } 
    inOrder(root->left);
}
int main() {
    return 0;
}