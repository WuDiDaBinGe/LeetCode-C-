#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 0 代表买入股票状态 此时手中有股票
    // 1 代表卖出股票状态 此时手中无股票 且要进入冷冻期
    // 2 代表冷冻期 此时手中无股票 但下一天可以买入
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        //base case
        dp[0][0] = -prices[0];
        dp[0][1] = INT_MIN;
        dp[0][2] = 0;
        for(int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }
        return max(dp[n -1][1], dp[n - 1][2]);
    }
    // 滚动数组优化
    int maxProfit1(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(3, 0);
        //base case
        dp[0] = -prices[0];
        dp[1] = INT_MIN;
        dp[2] = 0;
        for(int i = 1; i < n; ++i) {
            int a, b, c;
            a = dp[0], b= dp[1], c = dp[2];
            dp[2] = max(c, b);
            dp[1] = a + prices[i];
            dp[0] = max(a, c - prices[i]);
        }
        return max(dp[1], dp[2]);
    }
};