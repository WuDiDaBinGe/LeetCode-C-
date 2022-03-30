#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};
TreeNode* deserilize(string s) {
    s = s.substr(1, s.size() - 2);
    s += ',';
    vector<int> nums;
    int lastnum = 0;
    cout<<s<<endl;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ',') {
            if(lastnum > 0) nums.push_back(lastnum);
            else nums.push_back(0);
        }
        else if(s[i] > '0' && s[i] <'9')
            lastnum = s[i] - '0'; 
        else if(s[i] == 'l')
            lastnum = 0;
    }
    if(nums[0] == 0) return nullptr;
    vector<TreeNode*> nodes(nums.size(), nullptr);
    for(int i = 0; i < nodes.size(); i++) {
        if(nums[i] > 0) {
            nodes[i] = new TreeNode(nums[i]);
        }
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < nodes.size(); i++) {
        if(nums[i] > 0) {
            nodes[i]->left = 2 * i + 1 < nodes.size()?nodes[2 * i + 1]:nullptr;
            nodes[i]->right = 2 * i + 2 < nodes.size()?nodes[2 * i + 2]:nullptr;
        }
    }
    return nodes[0];
}
string dfs(TreeNode* root, vector<TreeNode*>& res, unordered_map<string, int>& mp) {
    if(root == nullptr) return "";
    //序列化
    string str = to_string(root->val) + "," + dfs(root->left, res, mp) + "," + dfs(root->right, res, mp);
    if(mp[str] == 1) {
        res.push_back(root);
    }
    mp[str]++;
    return str;
}
vector<TreeNode*> findDup(TreeNode* root) {
    vector<TreeNode*> res;
    unordered_map<string, int> mp;
    dfs(root, res, mp);
    return res;
}
int numNode(TreeNode* root) {
    if(root == nullptr) return 0;
    return max(numNode(root->left), numNode(root->right)) + 1;
}
vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> res;
    if(root == nullptr) return res;
    q.push(root);
    
}
int main() {
    string s; cin>>s;
    
    for() {

    }
    TreeNode* root = deserilize(s);
    vector<TreeNode*> res = findDup(root);
    for(int i = 0; i < res.size(); i++) {
        if(numNode(res[i]) > 1) {
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
//[1,4,3,1,null,2,null]