#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): left(nullptr), right(nullptr),val(x){};
};
vector<int> P,I;
TreeNode* build(int start, int end, int inStart, int inEnd){
    if(start > end || inStart > inEnd) return nullptr; 
    int value = P[start];
    TreeNode* root =new TreeNode(value);
    
    auto it = find(I.begin() + inStart, I.begin() + inEnd + 1, value);
    if(it == I.begin() + inEnd + 1){
        cout<<"Error"<<endl;
        return nullptr;
    }
    int left_size = distance(I.begin() + inStart, it);
    root->left = build(start + 1, start + left_size, inStart, inStart + left_size - 1);
    root->right = build(start + left_size + 1, end, inStart + left_size + 1, inEnd);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    if(n == 0) return nullptr;
    P = preorder;I = inorder;
    TreeNode* root = build(0, n - 1, 0, n - 1);
    return root;
}

void bfs(TreeNode* root) {
    queue<TreeNode*> stk;
    if(root == nullptr){
        cout<<"null"<<endl;
        return;
    }
    stk.push(root);
    while(!stk.empty()) {
        int n = stk.size();
        for(int i = 0; i < n; i++) {
            TreeNode* t = stk.front();stk.pop();
            cout<<t->val<<" ";
            if(t->left) stk.push(t->left);
            if(t->right) stk.push(t->right);
        }
        cout<<endl;
    }
}
int main() {
    vector<int> a = {3,9,20,15,7};
    vector<int> b = {9,3,15,20,7};
    TreeNode* root = buildTree(a, b);
    bfs(root);
    //auto it = find(I.begin() + 0 , I.begin() + 4 + 1, 3);
    //cout<<*it<<endl;
    return 0;
}