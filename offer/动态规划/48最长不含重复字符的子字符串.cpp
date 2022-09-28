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
/* 动态规划加哈希表
step 1：dp[i]dp[i]dp[i]表示以下标i结尾的字符串最长不含重复子串的长度，用哈希表记录是否重复出现字符，并记录其位置。
step 2：遍历字符串，哈希表中没有出现过的就不是重复，因此考虑dp[i]=dp[i−1]+1dp[i] = dp[i - 1] + 1dp[i]=dp[i−1]+1，即在前一个字符的基础上加上它。
step 3：哈希表中出现过的，这是重复的字符，考虑i−mp[s[i−1]]i - mp[s[i - 1]]i−mp[s[i−1]]，但是为了防止中间出现其他重复的字符，还是应该考虑它的前一个字符的基础，因此实际转移方程为dp[i]=min(dp[i−1]+1,i−mp[s[i−1]])dp[i] = min(dp[i - 1] + 1, i - mp[s[i - 1]])dp[i]=min(dp[i−1]+1,i−mp[s[i−1]])。
step 4：遍历过程中遇到的字符都要加入哈希表，同时维护最大的长度。
*/
int main() {

    return 0;
}