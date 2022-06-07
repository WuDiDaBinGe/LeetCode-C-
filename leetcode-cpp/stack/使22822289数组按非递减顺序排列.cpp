#include<bits/stdc++.h>
using namespace std;
// 单调栈 维护一个严格从栈底到栈顶递减的栈 记录弹出的最大时刻
int totalSteps(vector<int>& nums) {
    stack<pair<int, int>> stk;
    int res = INT_MIN;
    for(int num:nums) {
        int maxT = 0;
        while(!stk.empty() && stk.top().first <= num) {
            maxT = max(maxT, stk.top().second);
            stk.pop();
        }
        if(stk.empty()) maxT = 0;
        else maxT = maxT + 1;
        res = max(maxT, res);
        stk.emplace(num, maxT);
    }
    return res;
}
int main() {
    return 0;
}