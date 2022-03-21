#include<iostream>
#include<vector>
using namespace std;
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    int dp = nums[0];
    int res = dp;
    for(int i = 1; i < n; i++) {
        dp = max(dp + nums[i], nums[i]);
        res = max(res, dp);
    }
    return res;
}
int main() {
    vector<int> nums={5,4,-1,7,8};
    cout<<maxSubArray(nums)<<endl;
    return 0;
}