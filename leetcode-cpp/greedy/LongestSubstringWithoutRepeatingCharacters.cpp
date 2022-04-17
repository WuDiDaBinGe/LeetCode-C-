#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
// 滑动窗口
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;
    int left = 0, right = 0;
    int n = s.size();
    int res = INT8_MIN;
    if(n == 0 || n == 1) return n;
    while(right < n) {
        char c1 = s[right];
        window[c1]++;
        right++;
        while(window[c1] > 1) {
            char c2 = s[left];
            window[c2]--;
            left++;
        }
        res = max(right - left, res);
    }
    
    return res;
}
int main() {
    vector<string> s = {"abcabcbb", "bbbbb", "pwwkew", "au"};
    for(int i = 0; i < s.size(); i++) {
        cout<<lengthOfLongestSubstring(s[i])<<endl;
    }
    return 0;
}