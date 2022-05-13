#include<bits/stdc++.h>
using namespace std;
int findMaxForm(vector<string>& strs, int m, int n) {
    int len = strs.size();
    int dp[len + 1][m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    //base case
    for(int i = 1; i <= len; ++i) {
        int ones = 0, zeros = 0;
        for(int j = 0; j < strs[i - 1].size(); ++j) {
            if(strs[i - 1][j] == '0') zeros++;
            else ones++;
        }
        // 0
        for(int j = 0; j <= m; ++j) {
            // 1
            for(int k = 0; k <= n; ++k) {
                // no choice
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                // choice
                if(j - zeros >= 0 && k - ones >= 0)
                   dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1); 
            }
        }
    }
    return dp[len][m][n];
}
// 空间优化
int findMaxForm2(vector<string>& strs, int m, int n) {
    int len = strs.size();
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    //base case
    for(int i = 1; i <= len; ++i) {
        int ones = 0, zeros = 0;
        for(int j = 0; j < strs[i - 1].size(); ++j) {
            if(strs[i - 1][j] == '0') zeros++;
            else ones++;
        }
        // 0
        for(int j = m; j >=0; --j) {
            // 1
            for(int k = n; k >= 0; --k) {
                // no choice
                dp[j][k] = max(dp[j][k], dp[j][k]);
                // choice
                if(j - zeros >= 0 && k - ones >= 0)
                   dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1); 
            }
        }
    }
    return dp[m][n];
}
int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    cout<<findMaxForm2(strs, 5, 3)<<endl;
    return 0;
}