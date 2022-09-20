#include<bits/stdc++.h>
using namespace std;
/*
左右遍历:遍历两遍 从左到右 从右到左 记录左右两侧最高
*/
class Solution {
public:
    long long maxWater(vector<int>& arr) {
        int n = arr.size();
        if(n == 1 || n == 2) return 0;
        vector<int> lefts(n), rights(n);
        int l = arr[0];
        for(int i = 1; i < n; ++i){
            lefts[i] = l;
            l = max(l, arr[i]);
        }
        int r = arr[n - 1];
        for(int i = n - 2; i >= 0; --i){
            rights[i] = r;
            r = max(r, arr[i]);
        }
        int sum = 0;
        for(int i = 1; i < n -1; ++i) {
            int max_h =min(lefts[i], rights[i]);
            if(max_h > arr[i]) {
                sum += (max_h - arr[i]);
            }
        }
        return sum;
    }
};

/*单调栈*/
class Solution {
public:
    /**
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
    long long maxWater(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2) return 0;
        stack<int> stk;
        int res = 0;
        for(int i = 0; i < n;++i){
            while(!stk.empty() && arr[i] > arr[stk.top()]) {
                int h = arr[stk.top()]; stk.pop();
                if(stk.empty()) break;
                int width = i - stk.top() - 1;
                res += (min(arr[i], arr[stk.top()]) - h) * width;
            }
            stk.push(i);
        }
        return res;
    }
};