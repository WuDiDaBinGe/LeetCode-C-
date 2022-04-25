#include<bits/stdc++.h>
using namespace std;
// dp无空间优化
vector<double> dicesProbability(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1));
    //base case
    for(int i = 1; i <= 6; i++)
        dp[1][i] = 1;
    for(int i = 1; i <= n; i++)
        dp[i][i] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = i + 1; j <= i * 6; j++) {
            for(int count = 1; count <= 6; count++) {
                if(j - count >= 1)
                    dp[i][j] += dp[i - 1][j - count];
            }
        }
    } 
    vector<double> result;
    for(int i = 1; i <= 6 * n; i++) {
        if(dp[n][i] > 0) result.push_back((dp[n][i] + 0.0) / pow(6, n));
    }
    return result;
}
// dp 优化
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<int> dp(6 * n + 1);
        //base case
        for(int i = 1; i <= 6; i++)
            dp[i] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = i * 6; j >= i ; j--) {
                dp[j] = 0;
                for(int count = 1; count <= 6; count++) {
                    if(j - count >= i - 1)
                        dp[j] += dp[j - count];
                    else
                        break;
                }
            }
        } 
        vector<double> result;
        for(int i = n; i <= 6 * n; i++) {
            if(dp[i] > 0) result.push_back((dp[i] + 0.0) / pow(6, n));
        }
        return result;
    }
};
int main() {
    return 0;
}