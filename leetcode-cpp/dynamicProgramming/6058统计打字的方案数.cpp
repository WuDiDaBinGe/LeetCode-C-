#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int countTexts(string pressedKeys) {
    int n = pressedKeys.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1; dp[1] = 1;
    for(int i = 2; i <= n; ++i) {
        if(pressedKeys[i - 1] != pressedKeys[i - 2]) {
            dp[i] = dp[i - 1];
            continue;
        }
        char c = pressedKeys[i - 1];
        int count  = (c == '7' || c == '9') ? 4 : 3; 
        for(int j = 1; j <= count; ++j) {
            if((i - 1 - j >= 0 && pressedKeys[i - 1] == pressedKeys[i - 1 - j])) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            } else {
                // 如果第一不等于当前字符c 需要加上
                dp[i] = (dp[i] + dp[i - j]) % MOD;
                break;
            }
        }
        cout<<dp[i]<<endl;
    }
    return dp[n];
}
int main() {
    cout<<countTexts("22233")<<endl;
    return 0;
}