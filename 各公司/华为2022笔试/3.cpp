#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
using namespace std;
// 先从满二叉树中建树 
// 使用dfs+hashmap方式查找重复的子树
// 判断子树层数是否为1(要求节点数>2) 使用层序遍历反序列化出满二叉树的序列
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
    for(int i = 0; i < nodes.size()/2; i++) {
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
string levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    string res = "";
    if(root == nullptr) return res;
    q.push(root);
    int totallevel = numNode(root);
    int level = 0;
    while(!q.empty() && level < totallevel) {
        int count = q.size();
        for(int i = 0; i < count; i++) {
            TreeNode* t = q.front(); q.pop();
            if(t == nullptr) {
                res += "nullptr,";
                q.push(nullptr);
                q.push(nullptr);
            } else {
                res += (to_string(t->val) + ",");
                q.push(t->left);
                q.push(t->right);
            }
        }
        level++;
    }
    res.pop_back();
    return res;
}

int main() {
    string s; cin>>s;
    // TreeNode* root = new TreeNode(1);
    // TreeNode* r1 = new TreeNode(2);
    // TreeNode* r2 = new TreeNode(1);
    // TreeNode* r3 = new TreeNode(3);
    // root->left = r1;
    // root->right = r2;
    // r2->right = r3;
    // cout<<levelOrder(root)<<endl;
    TreeNode* root = deserilize(s);
    vector<TreeNode*> res = findDup(root);
    for(int i = 0; i < res.size(); i++) {
        if(numNode(res[i]) > 1) {
            cout<<"["<<levelOrder(res[i])<<"]"<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}