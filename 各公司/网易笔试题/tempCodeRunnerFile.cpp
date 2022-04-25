#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    TreeNode(): left(nullptr), right(nullptr){}
};
int main() {
    int m,n; cin>>m;cin>>n;
    // 记录子节点
    vector<int> left(m + 1, -1), right(m + 1, -1);
    for(int i = 0; i < n; i++) {
        int f, c; string dir;
        cin>>f;cin>>dir;cin>>c;
        if(dir == "right")
            right[f] = c;
        else
            left[f] = c;
    }
    int res = 0;
    for(int i = 1; i <= m; i++) {
        // 存在两个孩子
        if(left[i] != -1 && right[i] != -1){
            // 判断孩子是不是叶子节点
            int leftc = left[i], rightc = right[i];
            if((left[leftc] == -1 && right[leftc] == -1)
                && (left[rightc] == -1 && right[rightc] == -1))
                res += 1;
        }
    }
    cout<<res<<endl;
    return 0;
}