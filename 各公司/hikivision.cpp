#include<bits/stdc++.h>
using namespace std;
vector<int> pres, mids, afters;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* helpDec(vector<string>& datalist) {
    queue<TreeNode*> q;
    int n = datalist.size();
    if(n == 0) return nullptr;
    int cur = 0;
    TreeNode* root = new TreeNode(stoi(datalist[cur]));
    q.push(root);
    cur++;
    while (cur < n && !q.empty()) {
        TreeNode *t = q.front(); q.pop();
        if(cur < n) {
            TreeNode* l = new TreeNode(stoi(datalist[cur]));
            t->left = l;
            q.push(l);
        } else 
            break;
        cur++;
        if(cur < n) {
            TreeNode* r = new TreeNode(stoi(datalist[cur]));
            t->right = r;
            q.push(r);
        } else 
            break;
        cur++;
    }
    return root;
}
void preOrder(TreeNode* root){
    if(root == nullptr) return;
    pres.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}
void midOrder(TreeNode* root){
    if(root == nullptr) return;
    midOrder(root->left);
    mids.push_back(root->val);
    midOrder(root->right);
}
void afterOrder(TreeNode* root){
    if(root == nullptr) return;
    afterOrder(root->left);
    afterOrder(root->right);
    afters.push_back(root->val);
}
void printFormat(vector<int> order){
    cout<<"[";
    int n = order.size();
    for(int i = 0; i < n; ++i) {
        if(i == n -1) cout<<order[i];
        else cout<<order[i]<<", ";
    }
    cout<<"]"<<endl;
}
int main()
{
   string line; getline(cin, line);
   stringstream ss(line);
   string x;
   vector<string> nodeLists;
   while(getline(ss, x, ' ')) {
        nodeLists.push_back(x);
   }  
   TreeNode* root = helpDec(nodeLists);
   preOrder(root);
   midOrder(root);
   afterOrder(root);
   printFormat(pres);
   printFormat(mids);
   printFormat(afters);
   return 0;
}