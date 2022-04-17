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
// 递归
void rinOrder(TreeNode* root) {
    if(root == nullptr) return;
    rinOrder(root->right);
    if(k == 0) return;
    k--;
    if(k == 0) res = root->val;
    rinOrder(root->left);
}
int kthLargest(TreeNode* root, int k) {
    ak = k;
    rinOrder(root);
    return res;
}
int main() {
    return 0;
}