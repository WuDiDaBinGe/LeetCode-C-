#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void inorder(TreeNode* root,vector<int> &res) {
    if(root==nullptr) return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
}
vector<int> inorderTraversal1(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* p = root;
    while (!s.empty()||p!=nullptr) {
        if(p!=nullptr) {
            s.push(p);
            p = p->left;
        }
        else {
             p = s.top();
             s.pop();
             res.push_back(p->val);
             p = p->right;
        }
    }
    return res;
}
int main() {

}