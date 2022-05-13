#include<bits/stdc++.h>
using namespace std;
// 暴力dfs
int res = 0;
void dfs(int index, int sum, int n, int target, vector<int>& nums) {
    if(index == n) {
        if(sum == target) res++;
        return;
    }
    // purne
    dfs(index + 1, sum + nums[index], n, target, nums);
    dfs(index + 1, sum - nums[index], n, target, nums);
}
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    dfs(0, 0, n, target, nums);
    return res;
}
// 备忘录 + 递归
map<pair<int, int>, int> mem;
int dp(int index, int target, vector<int>& nums) {
    pair<int, int> state = make_pair(index, target);
    if(mem.find(state) == mem.end()) mem[state] = -1;
    if(index < 0) return 0;
    if(index == 0 && target == 0 && nums[0] == 0) return mem[state] = 2;
    if(index == 0 && (target == nums[0] || target == -nums[0])) return mem[state] = 1;
    if(mem[state] != -1) return mem[state];
    mem[state] = dp(index - 1, target - nums[index], nums) + dp(index - 1, target + nums[index], nums);
    return mem[state];
}
int findTargetSumWays2(vector<int>& nums, int target) {
    int n = nums.size();
    return dp(n - 1, target, nums);
}
// 动态规划 （sum - neg）-neg = target neg = (sum - target) / 2
// neg > 0 在数组中选取数使得和为neg  利用动态规划
int findTargetSumWays3(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < n; ++i)
        sum += nums[i];
    int diff = sum - target;
    if(diff % 2 == 1 || diff < 0)
        return 0;
    vector<vector<int>> dp(n + 1, vector<int>(diff / 2 + 1));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= diff / 2; ++j) {
            // 可选可不选
            if(j >= nums[i - 1]) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            } else {
                // 只能不选
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][diff / 2];
}
int main() {
    vector<int> nums = {1};
    cout<<findTargetSumWays2(nums, 1)<<endl;
    return 0;
}