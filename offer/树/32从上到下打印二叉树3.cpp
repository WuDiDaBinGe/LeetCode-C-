#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelTrase(root, 1, res);
        return res;
    }
    void levelTrase(TreeNode* root, int level, vector<vector<int>>& res) {
        if(root == nullptr) return;
        if(level > res.size())
            res.push_back(vector<int>());
        if(level % 2 == 0)
            res[level - 1].insert(res[level - 1].begin(), root->val);
        else
             res[level - 1].push_back(root->val);
        levelTrase(root->left, level + 1, res);
        levelTrase(root->right, level + 1, res);
    }
};
int main() {
    vector<int> a;
    a.insert(a.begin(), 1);
    a.insert(a.begin(), 2);
    cout<<a[0]<<" "<<a[1]<<endl;
    return 0;
}