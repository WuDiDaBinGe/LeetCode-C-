#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int nums[310];
int dp[310][310][310];

int dfs(int left, int right, int root) {
    if(left > right) return 0;
    if(dp[left][right][root] != -1) return dp[left][right][root];
    int res = 1e9;
    for(int i = left; i <= right; i++) {
        int leftv = dfs(left, i - 1, i);
        int rightv = dfs(i + 1, right, i);
        res = min(res, leftv + rightv + nums[root] * nums[i]);
    } 
    dp[left][right][root] = res;
    return res;
}
int main() {
    int n; cin>>n;
    memset(dp, -1, sizeof(dp));
    memset(nums, 0, sizeof(nums));
    for(int i = 1; i <= n; i++)
        cin>>nums[i];
    cout<<dfs(1, n, 0)<<endl;
    return 0;
}