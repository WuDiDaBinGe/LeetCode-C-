#include<bits/stdc++.h>
using namespace std;
// 0 表示有一只股票（买入）
// 1 表示无股票 （卖出）
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    //base case
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for(int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[n - 1][1];
}
// 滚动数组 优化
int maxProfit1(vector<int>& prices) {
    int n = prices.size();
    //base case
    int a  = -prices[0];
    int b  = 0;
    for(int i = 1; i < n; ++i) {
        int ta, tb; ta = a; tb = b;
        a = max(tb - prices[i], ta);
        b = max(tb, ta + prices[i]);
    }
    return b;
}

// 贪心思想
int maxProfit2(vector<int>& prices) {
    int n = prices.size();
    //base case
    int curMinPrice  = prices[0];
    int res = 0;
    for(int i = 1; i < n; ++i) {
        if(prices[i] > curMinPrice) {
            res += prices[i] - curMinPrice;
            curMinPrice = prices[i];
        } else {
            curMinPrice = prices[i];
        }
    }
    return res;
}