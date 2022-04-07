#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll A[3][100010];
// 动态规划
int main() {
    int n; cin>>n;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < n; j++)
            cin>>A[i][j];
    vector<vector<ll>> dp(3, vector<ll>(n));
    for(int j = 1; j < n; j++) {
        for(int i = 0; i < 3; i++) {
            // 三种选择
            ll dp1 = dp[0][j - 1] + abs(A[0][j - 1] - A[i][j]);
            ll dp2 = dp[1][j - 1] + abs(A[1][j - 1] - A[i][j]);
            ll dp3 = dp[2][j - 1] + abs(A[2][j - 1] - A[i][j]);
            dp[i][j] = min(dp1, min(dp2, dp3));
        }
    }
    ll res = LLONG_MAX;
    for(int i = 0; i < 3; i++) {
        res = min(res, dp[i][n - 1]);
    }
    cout<<res<<endl;
    return 0;
}