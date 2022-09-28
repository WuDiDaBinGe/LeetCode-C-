#include<bits/stdc++.h>
using namespace std;
struct BTreeNode {
    int val;
    BTreeNode *left;
    BTreeNode *right;
    BTreeNode() : val(0), left(nullptr), right(nullptr) {}
    BTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
struct TreeNode {
    int val;
    TreeNode* fchild, *brother;
    TreeNode(int d) : val(d) {
        fchild=nullptr;brother=nullptr;
    }
};
// 树转二叉树
void TreeNodeToBTreeNode(TreeNode* troot, BTreeNode* head) {
    if(troot == nullptr) return ;
    BTreeNode* temp = new BTreeNode(troot->val);
    head->left = temp;
    head = head->left;
    TreeNodeToBTreeNode(troot->fchild, head);
    TreeNode *work = troot->brother;
    BTreeNode* p = head;
    while(work != nullptr) {
        BTreeNode *temp2 = new BTreeNode(work->val);
        p->right = temp2;
        TreeNodeToBTreeNode(work->fchild, temp2);
        p = p->right;
        work = work->brother;
    }
    p->right = nullptr;
    return;
}
// Encodes a tree to a single string.
void preOrder(BTreeNode* root, string& s) {
    if(root == nullptr) {
        return;
    }
    s += to_string(root->val);
    s += '#';
    preOrder(root->left, s);
    preOrder(root->right, s);
}
int main(){
    TreeNode* r1 = new TreeNode(1);
    
    TreeNode* r2_1 = new TreeNode(21);
    TreeNode* r2_2 = new TreeNode(22);
    TreeNode* r2_3 = new TreeNode(23);
    TreeNode* r2_4 = new TreeNode(24);
    r1->fchild = r2_1;
    r2_1->brother = r2_2;
    r2_2->brother = r2_3;
    r2_3->brother = r2_4;
    TreeNode* r2_1_1 = new TreeNode(211);
    r2_1->fchild = r2_1_1;;
    TreeNode* r2_2_1 = new TreeNode(221);
    TreeNode* r2_2_2 = new TreeNode(222);
    r2_2->fchild = r2_2_1;
    r2_2_1->brother = r2_2_2;
    TreeNode* r2_4_1 = new TreeNode(241);
    TreeNode* r2_4_2 = new TreeNode(242);
    TreeNode* r2_4_3 = new TreeNode(243);
    r2_4->fchild = r2_4_1;
    r2_4_1->brother = r2_4_2;
    r2_4_2->brother = r2_4_3;
    BTreeNode* head = new BTreeNode(r1->val);
    TreeNodeToBTreeNode(r1->fchild, head);
    string res = "";
    preOrder(head, res);
    cout<<res<<endl;
    cout<<res<<endl;
    return 0;
}