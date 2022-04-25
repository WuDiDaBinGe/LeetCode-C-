#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//使用栈的方法
int longestValidParentheses(string s) {
    stack<int> stk;
    int last = -1;
    int res = 0;
    for(int i = 0;i < s.size(); i++) {
        if(s[i] == '(') {
            stk.push(i);
        }
        else {
            // no matching left
            if(stk.empty()) 
                last = i;
            // match a left 
            else {
                stk.pop();
                if(stk.empty())
                    res = max(res, i - last);
                else
                    res = max(res, i - stk.top());
            }
        }
    }
    return res;
}
//动态规划算法
// .....)) 和 ......()
int longestValidParentheses(string s) {
    int n = s.size();
    int res = INT8_MIN;
    if(n == 1 || n == 0) return 0; 
    vector<int> dp(n + 1, 0);
    for(int i = 2; i <= n; i++) {
        if(s[i - 1] == '(') 
            continue;
        if(s[i - 2] == '(')
            dp[i] = dp [i - 2] + 2;
        else if(i - 2 - dp[i -1] >= 0){
            if(s[i  - 2 - dp[i - 1]] == '(')
                dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
        }
        res = max(res, dp[i]);
    }
    return res == INT8_MIN ? 0 : res;
}
// O(1)空间复杂度
int main() {
    return 0;
}