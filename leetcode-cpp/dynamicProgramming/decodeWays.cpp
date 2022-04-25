#include<iostream>
#include<vector>
using namespace std;
int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    // base case 注意
    dp[0] = 1;
    if(s[0] == '0'){
        dp[1] = 0;
        return 0;
    } 
    else dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        // make choice 
        // 1. sperate last one
        // 0 的时候不能单独解码
        if(s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }
        // 2. joint last one
        // 
        if(s[i - 2] <= '2' && s[i - 2] > '0') {
            int num = (s[i - 2] - '0') * 10;
            num += s[i - 1] - '0';
            //cout<<num<<endl;
            if(num <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        cout<<dp[i]<<endl;
    }
    return dp[n];
}
int main(){
    return 0;
}