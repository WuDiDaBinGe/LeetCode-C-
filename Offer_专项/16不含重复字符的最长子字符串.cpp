#include<bits/stdc++.h>
using namespace std;
// 滑动窗口
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> windows;
    int n = s.size();
    if(n == 0) return 0;
    int res = INT_MIN;
    int left = 0, right = 0;
    while (right < n) {
        char c = s[right];
        windows[c]++;
        right++;
        while (windows[c] > 1) {
            int leftc = s[left];
            windows[leftc]--;
            left++;
        }
        res = max(res, right - left);
    }
    return res;
}
int main()
{
   
   return 0;
}