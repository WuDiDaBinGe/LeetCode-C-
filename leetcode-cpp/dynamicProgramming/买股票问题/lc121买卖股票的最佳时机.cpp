#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    // 记录当前最小值
    int minProfit = prices[0];
    int res = 0;
    for(int i = 1; i < n; ++i) {
        res = max(prices[i] - minProfit, res);
        minProfit = min(minProfit, prices[i]);
    }
    return res;
}