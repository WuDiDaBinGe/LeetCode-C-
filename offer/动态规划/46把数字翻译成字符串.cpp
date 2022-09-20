#include<bits/stdc++.h>
using namespace std;
int translateNum(int num) {
    string numstr = to_string(num);
    int n = numstr.size();
    vector<int> dp(n + 1, 0);
    if(n == 1) return 1;
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] += dp[i - 1];
        // 1x or 2x <= 25
        if((numstr[i - 2] == '2' && numstr[i - 1] <= '5') || numstr[i - 2] == '1') {
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];    
}
int main() {
    cout<<translateNum(12258)<<endl;
    return 0;
}
