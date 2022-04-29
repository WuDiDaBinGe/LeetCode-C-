#include<bits/stdc++.h>
using namespace std;
/*
    对于每一根柱子，其上盛放雨水的面积为：min(左边最高，右边最高) - height
    所以：
    1. 从左往右遍历 找到每一根柱子左边的最高
    2. 从右往左遍历 找到每一根柱子右边的最高
    3. 计算每一根柱子的可以盛放雨水的面积求和
*/
int trap(vector<int>& height) {
    int n = height.size();
    if(n <= 2) return 0;
    vector<int> left(n), right(n);
    for(int i = 1; i < n; ++i) {
        left[i] = max(height[i - 1], left[i - 1]);
    }
    int res = 0;
    for(int i = n - 2; i > 0; --i) {
        right[i] = max(right[i + 1], height[i + 1]);
        int min_value = min(right[i], left[i]);
        if(min_value > height[i]) {
            res += min_value -  height[i];
        }
    }
    return res;
}
// 使用单调栈
int trap(vector<int>& height) {
    int n = height.size();
    if(n <= 2) return 0;
    int res = 0;
    stack<int> stk;     //保存序号
    for(int i = 0; i < n; ++i) {
        while(!stk.empty() && height[i] > height[stk.top()]) {
            int h = height[stk.top()]; stk.pop();
            if(stk.empty()) break;
            int with = i - stk.top() - 1;
            res += (min(height[i], height[stk.top()]) - h) * with;
        }
        stk.push(i);
    }
    return res;
}
int main() {
    return 0;
}