#include<vector>
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    //暴力解法
    int largestRectangleArea(vector<int>& heights) {
        int res = INT8_MIN;
        int n  = heights.size();
        // 先将0 push进去 保证所有的元素均能出栈
        heights.push_back(0);
        stack<int> stk;
        for(int i = 0; i <= n; i++) {
            while(!stk.empty() && heights[i] <= heights[stk.top()]) {
                int index = stk.top();
                stk.pop();
                int left = 0;
                if(stk.empty())
                    left = -1;
                else
                    left = stk.top();
                res = max(res, (i - left - 1) * heights[index]);
            }
            stk.push(i);
        }
        return res;
    }
};