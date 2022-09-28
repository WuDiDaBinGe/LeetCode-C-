#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 两次dfs
class Solution {
public:
    unordered_map<TreeNode*, vector<int>> mp;
	int res_num = 0;
    void dfs(TreeNode* root, int target) {
		if(root ==nullptr) return;
		if(target == root->val) {
			res_num++;
			// return;  不能return 可以接着往下搜寻 因为后面的路径加起来可能为0
		}
		dfs(root->left, target - root->val);
		dfs(root->right, target - root->val);
	}
	int FindPath(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
		dfs(root, sum);
		FindPath(root->left, sum);
		FindPath(root->right, sum);
		return res_num;
    }
};
class Solution1 {
public:
	// 使用map记录下遍历路径上的值 寻找cur_sum - target的值在之前是否出现过
    unordered_map<int, int> path;
	int res_num = 0;
    void dfs(TreeNode* root, int cur_sum, int target) {
		if(root ==nullptr) return;
		cur_sum += root->val;
		int gap = cur_sum - target;
		if(path.find(gap) != path.end()) {
			res_num += path[gap];
			// return;  不能return 可以接着往下搜寻 因为后面的路径加起来可能为0
		}
		// 
		path[cur_sum]++;
		dfs(root->left, cur_sum, target);
		dfs(root->right, cur_sum, target);
		path[cur_sum]--;
	}
	int FindPath(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
		path[0] = 1;
		dfs(root, 0, sum);
		return res_num;
    }
};