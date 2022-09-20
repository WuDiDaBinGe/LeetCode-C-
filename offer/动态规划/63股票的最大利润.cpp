#include<bits/stdc++.h>
using namespace std;
// 贪心
int maxProfit(vector<int>& prices) {
    int curMin = INT_MAX;
    int res = 0;
    int n = prices.size();
    for(int i = 0; i < n; i++) {
        if(i > 0) {
            res = max(res, prices[i] - curMin);
        }
        curMin = min(curMin, prices[i]);
    }    
    return res;    
}
// 动态规划 dp[i]表示[0 - i]的最大利润
int maxProfit(vector<int>& prices) {
    int dp = 0;
    int n = prices.size();
    if(n == 0) return 0;
    int curMin = prices[0];
    for(int i = 1; i < n; i++) {
        dp = max(dp, prices[i] - curMin);
        curMin = min(curMin, prices[i]);
    }
    return dp;
}

int main() {
    return 0;
}