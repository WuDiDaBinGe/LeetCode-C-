#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp = vector<bool>(s.size() + 1, false);
        //base case
        dp[0] = true;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        // 一定要注意下标
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 0; j <= i - 1; j++) {
                if(dict.find(s.substr(j, i - j)) != dict.end() ) {
                    dp[i] = dp[j];
                    if(dp[i]) break;
                }
            }
        }
        return dp[s.size()];
    }
};