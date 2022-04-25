#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
class Solution {
public:
    // 动态规划
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 0);
        if(n == 2) return 1;
        if(n == 3) return 2;
        //base case
        for(int i = 0; i <= n; i++)
            dp[i] = i;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                dp[i] = max(dp[i], dp[j] * (i - j));
            }
        }
        return dp[n];
    }
    // 贪心
    int cuttingRope2(int n) {
        if(n < 2)
            return 0;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        int t3 = n / 3;
        if(n - t3 * 3 == 1)
            t3--;
        int t2 = (n - t3 * 3) / 2;
        return pow(3, t3) + pow(2, t2); 
    }
};