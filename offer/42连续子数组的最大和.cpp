#include<bits/stdc++.h>
using namespace std;
// 规律前缀和 <0 从新开始 >0 加上本地元素
int maxSubArray(vector<int>& nums) {
    int curSum = nums[0];
    int res = INT_MIN;
    for(int i = 1; i < nums.size(); i++) {
        if(curSum < 0) curSum = nums[i];
        else curSum += nums[i];
        res = max(curSum, res);
    }
    return res;
}
//dp
int maxSubArray(vector<int>& nums) {
    int dp = nums[0];
    int n = nums.size();
    int res = nums[0];
    for(int i = 1; i < n; i++) {
        dp = max(dp + nums[i], nums[i]);
        res = max(dp, res);
    }
    return res;
}
// 
int main() {
    return 0;
}