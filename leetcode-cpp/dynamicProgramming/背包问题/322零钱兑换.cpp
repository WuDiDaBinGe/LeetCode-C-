#include<bits/stdc++.h>
using namespace std;
// 完全背包
int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) return 0;
    int n =coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));
    //base case
    for(int i = 0; i <= amount; ++i)
        dp[0][i] = INT_MAX;
    for(int i = 0; i <= n; ++i)
        dp[i][0] = 0;
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= amount; ++j) {
        int p = coins[i - 1];
        int res = INT_MAX;
        res = min(res, dp[i-1][j]);
        if(j - p >= 0 && dp[i][j - p] == INT_MAX)
            res = min(res, INT_MAX);
        else if(j - p >= 0 && dp[i][j - p] < INT_MAX)
            res = min(res, dp[i][j - p] + 1);
        dp[i][j] = res;
    }
    return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
}
// dfs + 记忆化搜索
class Solution {
    vector<int>count;
    int dp(vector<int>& coins, int rem) {
        if (rem < 0) return -1;
        if (rem == 0) return 0;
        if (count[rem - 1] != 0) return count[rem - 1];
        int Min = INT_MAX;
        for (int coin:coins) {
            int res = dp(coins, rem - coin);
            if (res >= 0 && res < Min) {
                Min = res + 1;
            }
        }
        count[rem - 1] = Min == INT_MAX ? -1 : Min;
        return count[rem - 1];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        count.resize(amount);
        return dp(coins, amount);
    }
};
int main() {

}