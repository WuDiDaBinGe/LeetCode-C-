#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 使用递归的方法
bool verifyPostorder(vector<int>& postorder) {
    int n = postorder.size();
    if(n < 2) return true;
    return verify(postorder, 0, n - 1);
}
bool verify(vector<int>& postorder, int left, int right) {
    if(left >= right) return true;
    //寻找左子树 和 右子树 right为此时的根
    int i = left;
    while(i < right && postorder[i] < postorder[right]) {
        i++;
    }
    bool check =false;
    // 检查右子树是否都大与根节点right, 不满足则不是二叉搜索树
    for(int j = i; j < right; j++) {
        if(postorder[j] < right) {
            check = true;
            break;
        }
    }
    if(check) return false;
    bool left_flag = verify(postorder, left, i - 1);
    bool right_flag = verify(postorder, i, right - 1);
    return left_flag && right_flag;
}
// 使用递归构建二叉搜索树的方法
bool verifyPostorder2(vector<int>& postorder) {
    int n = postorder.size();
    if(n <= 1) return true;
    build(postorder, INT_MIN, INT_MAX);
    return postorder.size() == 0;
}
void build(vector<int>& postorder, int minValue, int maxValue) {
    if(postorder.size() == 0) return;
    int n = postorder.size();
    int val = postorder[n - 1];
    if(val < minValue || val > maxValue) return;
    postorder.pop_back();
    build(postorder, val + 1, maxValue);
    build(postorder, minValue, val - 1);
}
// 使用单调栈的方式 维护一个从栈底到栈顶递增的单调栈
// https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/by-gahing-qk9k/
bool verifyPostorder(vector<int>& postorder) {
    stack<int> stk;
    stk.push(INT_MIN);
    int root = INT_MAX;
    for(int i = postorder.size() - 1; i >= 0; i--) {
        if(postorder[i] > root) return false;
        while(!stk.empty() && stk.top() > postorder[i]) {
            root = stk.top();
            stk.pop();
        }
        stk.push(postorder[i]);
    }
    return true;
}