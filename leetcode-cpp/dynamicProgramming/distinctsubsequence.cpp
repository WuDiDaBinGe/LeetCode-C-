#include<iostream>
#include<vector>
using namespace std;
//二维矩阵dp 无空间优化
int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<uint64_t>> dp = vector<vector<uint64_t>>(n + 1, vector<uint64_t>(m + 1, 0));
    for(int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }
    //base case
    for(int j = 0; j <= n; j++) {
        dp[j][0] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            //相等时 可以有两种情况 1. 加上本字符 2、 不加本字符
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}
// 滚动数组 优化空间
int main(){
    return 0;
}