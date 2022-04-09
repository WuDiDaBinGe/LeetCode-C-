#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Encodes a tree to a single string.
void preOrder(TreeNode* root, string& s) {
    if(root == nullptr) {
        s += "#,";
        return;
    }
    s += to_string(root->val);
    s += ',';
    preOrder(root->left, s);
    preOrder(root->right, s);
}
string serialize(TreeNode* root) {
    string res ="";
    preOrder(root, res);
    return res;
}
TreeNode* helpDeseria(vector<string>& datalist) {
    if(datalist.size() > 0 && datalist[0] == "#") {
        datalist.erase(datalist.begin());
        return nullptr;
    }
    TreeNode* node = new TreeNode(stoi(datalist[0]));
    datalist.erase(datalist.begin());
    node->left = helpDeseria(datalist);
    node->right = helpDeseria(datalist);
    return node;
}   
// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    vector<string> list;
    stringstream ss(data);
    string x;
    while (getline(ss, x, ',')) {
        list.push_back(x);
    }
    return helpDeseria(list);
}
// Encodes a tree to a single string.
// 使用层序遍历
string serialize1(TreeNode* root) {
    string s = "";
    queue<TreeNode*> q;
    if(root == nullptr) {
        s += "#,";
        return s;
    }
    q.push(root);
    while (!q.empty()) {
        int count = q.size();
        for(int i = 0; i < count; i++) {
            TreeNode* t = q.front(); q.pop();
            if(t == nullptr) {
                s += "#,";
            } else{
                s += to_string(t->val);
                s += ',';
                q.push(t->left);
                q.push(t->right);
            }
        }
    }
    return s;
}

// Decodes your encoded data to tree.
TreeNode* deserialize1(string data) {
    stringstream ss(data);
    string x;
    vector<string> datalist;
    while(getline(ss, x, ',')) {
        datalist.push_back(x);
    }
    queue<TreeNode*> q;
    if(datalist[0] == "#") return nullptr;
    int cur = 0;
    TreeNode* root = new TreeNode(stoi(datalist[cur]));
    q.push(root);
    cur++;
    while (cur < datalist.size() && !q.empty()) {
        TreeNode *t = q.front(); q.pop();
        if(datalist[cur] != "#") {
            TreeNode* l = new TreeNode(stoi(datalist[cur]));
            t->left = l;
            q.push(l);
        }
        cur++;
        if(datalist[cur] != "#") {
            TreeNode* r = new TreeNode(stoi(datalist[cur]));
            t->right = r;
            q.push(r);
        }
        cur++;
    }
    return root;
}
int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);
    root->left = left;
    root->right = right;
    cout<<serialize1(root)<<endl;
    return 0;
}

