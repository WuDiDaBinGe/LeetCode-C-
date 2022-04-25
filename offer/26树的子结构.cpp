#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};
bool isSubStructure(TreeNode* A, TreeNode* B) {
    if(B == NULL || A == NULL)
        return false;
    //遍历A中每个节点，A树中任一节点包含B就能返回true
    return iscontain(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
}
//包含：以A为根的数是否包含B（必须从A开始）
bool iscontain(TreeNode* A, TreeNode* B){
    if(B == NULL)
        return true;
    if(A == NULL || A->val != B->val)
        return false;
    return iscontain(A->left, B->left) && iscontain(A->right, B->right);
}
int main() {
    return 0;
}