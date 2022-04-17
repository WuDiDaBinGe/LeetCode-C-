#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string longestPalindrome(string s) {
    int s_len = s.length();
    // 表示在区间[i，...j]是否是是字符串
    int dp[s_len][s_len]; 
    // init base case
    for(int i=0;i<s_len;i++){
        for(int j=0;j<s_len;j++){
            if(i==j)
                dp[i][j]=1;
            else
                dp[i][j]=-1;
        }
    }
    // Traverse dp table
    for (int col=1;col<s_len;col++) {
        for (int row=0;row<col;row++) {
            if (row==(col-1)&&s[row]==s[col]) {
                dp[row][col] = 1;
                continue;
            }
            if(dp[row+1][col-1]==1&&s[row]==s[col]) {
                dp[row][col] = 1;
            }

        }
    }
    int res_len=-1;
    int s_index;
    for (int i = 0; i < s_len; i++) {
        for (int j=i;j < s_len; j++) {
            if(dp[i][j] == 1 && (j-i+1)>res_len) {
                s_index = i;
                res_len = (j-i+1);
            }
        }
    }
    return s.substr(s_index, res_len);
}
int main() {
    cout<<longestPalindrome("bb")<<endl;
    return 0;
}