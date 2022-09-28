#include<bits/stdc++.h>
using namespace std;
// 前缀和 + 二分查找
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n);
    int res = INT_MAX;
    prefix[0] = nums[0];
    for(int i = 1; i < n; ++i) {
        prefix[i] = nums[i] + prefix[i - 1];
    }
    auto index = lower_bound(prefix.begin(), prefix.end(), target);
    if(index != prefix.end()) {
        int len = distance(prefix.begin(), index) + 1 ;
        res = min(res, len);
    }
    for(int i = 0; i < n; ++i) {
        int flag = target + prefix[i];
        auto index = lower_bound(prefix.begin() + i, prefix.end(), flag);
        if(index != prefix.end()) {
            int len = distance(prefix.begin() + i, index) ;
            res = min(res, len);
        }
    }
    return res == INT_MAX ? 0 : res;
}
// 滑动窗口
int minSubArrayLen(int target, vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    int res = INT_MAX;
    int left = 0, right = 0;
    while(right < n) {
        sum += nums[right];
        right++;
        while(sum >= target) {
            res = min(res, right - left);
            sum -= nums[left];
            left++;
        }
    }
    return res == INT_MAX ? 0 : res;
}
int main() {
    return 0;
}