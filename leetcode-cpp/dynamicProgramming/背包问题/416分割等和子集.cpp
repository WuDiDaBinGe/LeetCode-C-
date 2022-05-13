#include<bits/stdc++.h>
using namespace std;
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return false;
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += nums[i];
    }
    if(sum % 2 == 1) return false;
    sum = sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    // base case
    dp[0][0] = true;
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = true;
    }
    // itera
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= sum; ++j) {
            // 不选
            dp[i][j] = dp[i][j] || dp[i - 1][j];
            // 选
            if(j - nums[i - 1] >= 0)
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
        }
    }
    return dp[n][sum];
}
// 优化dp
bool canPartition2(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return false;
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += nums[i];
    }
    if(sum % 2 == 1) return false;
    sum = sum / 2;
    vector<bool> dp(sum + 1, false);
    // base case
    dp[0] = true;
    // itera
    for(int i = 1; i <= n; ++i) {
        for(int j = sum; j >= 1; --j) {
            // 不选
            dp[j] = dp[j] || dp[j];
            // 选
            if(j - nums[i - 1] >= 0)
                dp[j] = dp[j] || dp[j - nums[i - 1]];
        }
    }
    return dp[sum];
}
int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout<<canPartition2(nums)<<endl;
    return 0;
}