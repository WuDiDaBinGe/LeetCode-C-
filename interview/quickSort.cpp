#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr),right(nullptr){}
    TreeNode(char x):val(x),left(nullptr),right(nullptr){}
};
TreeNode* buildNode(char w) {
    if(w=='*') return 0;
    return new TreeNode(w);
}
void preOrder(TreeNode* root) {
    if(root == nullptr) return;
    cout<<root->val;
    preOrder(root->left);
    preOrder(root->right);
}
TreeNode* findNode(TreeNode* root, char w){
    if(root == nullptr) return nullptr;
    if(root->val == w) return root;
    TreeNode* ans;
    if(root->left !=nullptr) ans = findNode(root->left, w);
    if(ans != nullptr) return ans;
    if(root->right != nullptr) ans = findNode(root->right, w);
    if(ans != nullptr) return ans;
}
int main() {
    int n;
    cin>>n;
    char r,lc,rc;
    cin>>r>>lc>>rc;
    TreeNode* root = buildNode(r);
    root->left = buildNode(lc);
    root->right = buildNode(rc);
    for(int i = 1; i < n; i++){
        cin>>r>>lc>>rc;
        TreeNode* t  = findNode(root, r);
        t->left = buildNode(lc); t->right = buildNode(rc);
    }
    preOrder(root);
    return 0;
}