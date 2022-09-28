#include<bits/stdc++.h>
using namespace std;
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k == 0) return 0;
    int n = nums.size();
    int left = 0, right = 0;
    int sum = 1;
    int res = 0;
    while(right < n) {
        sum *= nums[right];
        right++;
        // 防止[1,1,1] 1这种情况
        while(left < right && sum >= k) {
            sum /= nums[left];
            left++;
        }
        res += (right - left);
    }
    return res;
}