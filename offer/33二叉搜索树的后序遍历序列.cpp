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
    //寻找左子树 和 右子树 right为此时的跟
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
