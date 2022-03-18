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
void preorder(TreeNode* root,vector<int> &res) {
    if(root==nullptr) return;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preorder(root, res);
    return res;
}
/*use stack*/
vector<int> preorderTraversal1(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    if(root!=nullptr)  s.push(root);
    while (!s.empty()) {
        TreeNode* tmp = s.top();
        s.pop();
        res.push_back(tmp->val);

        if (tmp->right!=nullptr) s.push(tmp->right);
        if (tmp->left!=nullptr) s.push(tmp->left); 
    }
    return res;
}
int main() {

}