#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 深度优先遍历
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(root == nullptr) return res;
        path.push_back(root->val);
        dfs(root, target - root->val);
        return res;
    }
    void dfs(TreeNode* node, int gap) {
        // border
        if(node == nullptr)  return ;
        int val = node->val;
        // valid
        if(gap == 0 && node->left == nullptr && node->right == nullptr) {
            res.push_back(path);
            return;
        }
        // make choice
        if(node->left != nullptr) {
            path.push_back(node->left->val);
            dfs(node->left, gap - node->left->val);
            path.pop_back();
        }
        if(node->right != nullptr) {
            path.push_back(node->right->val);
            dfs(node->right, gap - node->right->val);
            path.pop_back();
        }
    }
};
// 宽度优先遍历
class Solution1 {
public:
    vector<vector<int>> resv;
    unordered_map<TreeNode*, TreeNode*> parentNode;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        queue<TreeNode*> nodeq;
        queue<int> sumq;
        if(root == nullptr) return resv;
        parentNode[root] = nullptr;
        nodeq.push(root);
        sumq.push(0);
        while (!nodeq.empty()) {
            TreeNode *t = nodeq.front(); nodeq.pop();
            int res = sumq.front() + t->val; sumq.pop();
            if(res == target && t->left == nullptr && t->right == nullptr) {
                resv.push_back(getPath(t));
            } 
            if(t->left != nullptr) {
                // 记录父节点
                parentNode[t->left] = t;
                nodeq.push(t->left);
                sumq.push(res);
            }
            if(t->right != nullptr) {
                parentNode[t->right] = t;
                nodeq.push(t->right);
                sumq.push(res);
            }
        }
        return resv;
    }
    vector<int> getPath(TreeNode* node) {
        vector<int> path;
        TreeNode* cur = node;
        while(cur) {
            path.insert(path.begin(), cur->val);
            cur = parentNode[cur];
        }
        return path;
    }
};