#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};
TreeNode* mirrorTree(TreeNode* root) {
    if(root == nullptr) return nullptr;
    TreeNode* l, *r;
    l = mirrorTree(root->right);
    r = mirrorTree(root->left);
    root->left = l;
    root->right = r;
    return root;
}
// 使用栈
TreeNode* mirrorTree2(TreeNode* root) {
    if(root == nullptr) return nullptr;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        TreeNode* t = st.top();st.pop();
        // 先访问右节点
        if(t->left != nullptr) st.push(t->left);
        if(t->right != nullptr) st.push(t->right);

        TreeNode* temp = t->left;
        t->left = t->right;
        t->right = temp;
    }
    return root;
}
int main() {
    return 0;
}