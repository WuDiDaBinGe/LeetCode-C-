#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string s1, s2;
    vector<vector<int>> memorizes;
    int minDistance(string word1, string word2) {
        s1 = word1; s2 = word2;
        int n = s1.size();
        int m = s2.size();
        memorizes = vector<vector<int>>(n, vector<int>(m, 0));
        return dp(n - 1, m - 1);
    }
    int dp(int i, int j) {
        // base case
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        if(memorizes[i][j] != 0) return memorizes[i][j];
        // get choice
        // 相等无需操作
        if(s1[i] == s2[j]){
            return memorizes[i][j] = dp(i - 1, j - 1);
        }
        int res = min(dp(i, j - 1), dp(i - 1, j));
        res = min(res, dp(i - 1, j - 1));
        memorizes[i][j] = res + 1;
        // 不相等 需要操作
        return memorizes[i][j];
    }
};
int minDistace(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i <= m; i++) {
        dp[i][0] = i + 1;
        dp[0][i] = i + 1;
    }
    // base case
    for(int i = 1; i<= n; i++) {
        // for(int j = 1; j<= m; j++) {
        //     if(word1[i] == word2[j])
        //         dp[i][j] = dp[i - 1][j - 1];
        //     else{
        //         dp[i][j] = min(dp[i][]);
        //     }
        // }
    }
}
int main(){
    return 0;
}