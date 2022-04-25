#include<bits/stdc++.h>
using namespace std;
// 滑动窗口
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;
    int n = s.size();
    int left = 0, right = 0;
    int res = INT_MIN;
    if(n == 1) return 1;
    while(right < n) {
        char c = s[right];
        window[c]++;
        right++;
        while (window[c] > 1) {
            char c1 = s[left];
            window[c1]--;
            left++;
        }
        res = max(res, right - left);
    }
    return res;
}
// 动态规划
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if(n == 0) return 0;
    if(n == 1) return 1;
    vector<int> dp(n, 0);
    int res = INT_MIN;
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        int j = i - 1;
        for(j; j >= 0; j--) {
            if(s[j] == s[i])
                break;
        }
        // 前面没有重复的
        if(j < 0) {
            dp[i] = dp[i - 1] + 1;
        } else {
            // 重复字符在i - 1 为结尾的最长无重复字串中
            if(j >= i -  dp[i - 1]) {
                dp[i] = i - j;
            } 
            // 重复字符在i - 1 为结尾的最长无重复字串外
            else{
                dp[i] = dp[i - 1] + 1;
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}
int main() {

    return 0;
}