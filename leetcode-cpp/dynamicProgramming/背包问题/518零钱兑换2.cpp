#include<bits/stdc++.h>
using namespace std;
int change(int amount, vector<int>& coins) {
     int n = coins.size();
     vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
       for(int i = 0; i <= amount; ++i) {
           dp[0][i] = 0;
       } 
       for(int i = 0; i <= n; ++i) {
           dp[i][0] = 1;
       }
       for(int i = 1; i <= n; ++i)
       for(int j = 1; j <= amount; ++j) {
           dp[i][j] = dp[i - 1][j];
           if(j - coins[i - 1] >= 0) {
               dp[i][j] += dp[i][j - coins[i - 1]];
           }
       }
       return dp[n][amount];
}
// 一维优化
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<int> dp(amount + 1);
    for(int i = 0; i <= amount; ++i) {
        dp[i] = 0;
    } 
    dp[0] = 1;
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= amount; ++j) {
        dp[j] = dp[j];
        if(j - coins[i - 1] >= 0) {
            dp[j] += dp[j - coins[i - 1]];
        }
    }
    return dp[amount];
}
int main(){
    return 0;
}