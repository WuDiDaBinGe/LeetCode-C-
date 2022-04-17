#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int longestPalindromeSubseq(string s) {
    int s_len = s.length();
    if(s_len==0||s_len==1) return s_len;
    int dp[s_len][s_len];
    fill_n(&dp[0][0], s_len*s_len, 0);
    for(int i=0;i<s_len;i++)
        dp[i][i]=1;
    for(int col=1;col<s_len;col++){
        for (int row=col-1;row>=0;row--) {
            if (s[col] == s[row]) {
                if((col-row)==1) 
                    dp[row][col]=2;
                else
                    dp[row][col]=dp[row+1][col-1]+2;
            }
            else {
                dp[row][col] = max(dp[row][col-1],dp[row+1][col]);
            }
        }
    }
    for (int i =0;i<s_len;i++) {
        for(int j=0;j<s_len;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][s_len-1];
}
// 状态压缩版本
int longestPalindromeSubseqSave(string s) {
    int s_len = s.length();
    if(s_len==0||s_len==1) return s_len;
    vector<int> dp(s_len, 1);
    for(int col=1;col<s_len;col++){
        int pre = 0;
        for (int row=col-1;row>=0;row--) {
            int temp = dp[row];
            if (s[col] == s[row]) {
                dp[row] = pre + 2;
            }
            else {
                dp[row] = max(dp[row],dp[row+1]);
            }
            pre = temp;
        }
    }
    return dp[0];
}
int main(){
    cout<<longestPalindromeSubseqSave("bbbab")<<endl;
    return 0;
}