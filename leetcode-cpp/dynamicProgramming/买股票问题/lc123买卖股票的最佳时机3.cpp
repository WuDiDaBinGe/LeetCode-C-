#include<bits/stdc++.h>
using namespace std;
// 需要分析出五个状态 
// 未进行过任何操作； 全为0
// 只进行过一次买操作；
// 进行了一次买操作和一次卖操作，即完成了一笔交易；
// 在完成了一笔交易的前提下，进行了第二次买操作；
// 完成了全部两笔交易。
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> dp(4, 0);
    vector<int> tmp(4, 0);
    // 注意边界条件
    dp[0] = -prices[0]; dp[1] = 0;
    dp[2] = -prices[0]; dp[1] = 0;
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < 4; ++j) tmp[j] = dp[j];
        dp[0] = max(tmp[0],  -prices[i]);
        dp[1] = max(tmp[1], tmp[0] + prices[i]);
        dp[2] = max(tmp[2], tmp[1] - prices[i]);
        dp[3] = max(tmp[3], tmp[2] + prices[i]);
    }
    return max(dp[1], dp[3]);
}