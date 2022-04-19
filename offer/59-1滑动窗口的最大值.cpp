#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> result;
    if(n == 0) return result;
    int left = 0, right = k - 1;
    int curMax = *max_element(nums.begin(), nums.begin() + k);
    result.push_back(curMax);
    while(right + 1 < n) {
        if(nums[left] == curMax) {
            curMax = *max_element(nums.begin() + left + 1, nums.begin() + right + 1);
        } 
        left++;
        right++;
        if(nums[right] > curMax) {
            curMax = nums[right];
        }
        result.push_back(curMax);
    }
    return result;
}
int main() {
    vector<int> nums = {1, -1};
    maxSlidingWindow(nums, 1);
    return 0;
}