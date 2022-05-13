#include<bits/stdc++.h>
using namespace std;
// 多维01背包问题 最后一维表示利润至少为k
const int MOD = 1e9 + 7;
int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    int len = group.size();
    int dp[len + 1][n + 1][minProfit + 1];
    memset(dp, 0, sizeof(dp));
    // base case
    dp[0][0][0] = 1;
    for(int i = 1; i <= len; ++i)
    for(int j = 0; j <= n; ++j)
    for(int k = 0; k <= minProfit; ++k) {
        if(j - group[i - 1] >= 0) {
            // 注意这里k的递推公式
            dp[i][j][k] = (dp[i - 1][j][k] + dp[i - 1][j - group[i - 1]][max(k - profit[i - 1], 0)]) % MOD;
        }
        else
            dp[i][j][k] =dp[i - 1][j][k];
        //cout<<dp[i][j][k]<<endl;
    }
    int sum = 0;
    for(int i = 0; i <= n; ++i) {
        sum = (sum + dp[len][i][minProfit]) % MOD;
    }
    return sum;
}

int main() {
    return 0;
}