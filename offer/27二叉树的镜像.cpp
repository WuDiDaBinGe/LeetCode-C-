#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};
// 递归表示
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
        swap(t->left, t->right);
        // 先访问右节点
        if(t->right != nullptr) st.push(t->right);
        if(t->left != nullptr) st.push(t->left);
    }
    return root;
}
// 使用队列
TreeNode* mirrorTree3(TreeNode* root) {
    if(root == nullptr) return nullptr;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* t = q.front();q.pop();
        swap(t->left, t->right);
        // 先访问右节点
        if(t->left != nullptr) q.push(t->left);
        if(t->right != nullptr) q.push(t->right);
        
    }
    return root;
}
int main() {
    return 0;
}