#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    /**
     * 递归遍历
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr && sum == 0) return false;
        if(root == nullptr && sum != 0) return false;
        if(root->left == nullptr && root->right == nullptr && root->val == sum) return true;
        if(root->left == nullptr && root->right == nullptr && root->val != sum) return false;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
    // 宽度便利 使用pair记录root到此的值
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        TreeNode* cur = root;
        queue<pair<TreeNode*, int>> q;
        q.push({cur, cur->val});
        while(!q.empty()) {
            pair<TreeNode*, int> node = q.front();q.pop();
            if(node.first->left) {
                q.push({node.first->left, node.first->left->val + node.second});
            }
            if(node.first->right) {
                q.push({node.first->right, node.first->right->val + node.second});
            }
            if(node.first->left == nullptr && node.first->right == nullptr && node.second == sum) {
                return true;
            }
        }
        return false;
    }
    
};