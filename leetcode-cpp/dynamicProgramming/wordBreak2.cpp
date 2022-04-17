#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;
class Solution {
public:
    stack<string> path;
    vector<string> res;
    vector<bool> dp;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        dp = vector<bool>(n + 1, false);
        dp[0] = true;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        //cout<<"dp finished"<<endl;
        for(int i = 1; i <= n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(dp[j] && dict.find(s.substr(j, i - j)) != dict.end()){
                    dp[i] = true;
                    break;
                }
            }
            //cout<<dp[i]<<" ";
        }
        //cout<<endl;
        dfs(s.size() - 1, s, dict);
        return res;
    }
    void dfs(int index, string s, unordered_set<string> dict) {
        if(index < 0) {
            stack<string> stk = path;
            string sr = "";
            while(!stk.empty()) {
                sr += stk.top();
                stk.pop();
                if(!stk.empty()) sr += " ";
            }
            res.push_back(sr);
            return;
        }
        // purne
        if(!dp[index + 1]) return;
        // iter
        for(int i = index; i >= 0; i--) {
            string substr_ = s.substr(i, index - i + 1);
            if(dp[i] && dict.find(substr_) != dict.end()) {
                //cout<<substr_<<endl;
                path.push(substr_);
                dfs(i - 1, s, dict);
                path.pop();
            }
            
        }
    }
};