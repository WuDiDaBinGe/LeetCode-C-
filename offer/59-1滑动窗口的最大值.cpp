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
// 维护一个单调的双端队列
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    if(n == 0) return {};
    if(n == 1) return nums;
    int left = 1- k, right = 0;
    deque<int> dq;
    vector<int> res;
    while(right < n) {
        if(left >= 1 && dq.front() == nums[left - 1]) dq.pop_front();
        while(!dq.empty() && dq[dq.size() - 1] < nums[right]) dq.pop_back();
        dq.push_back(nums[right]);
        if(left >= 0) res.push_back(dq.front());
        right++;
        left++;
    }
    return res;
}
int main() {
    vector<int> nums = {1, -1};
    maxSlidingWindow(nums, 1);
    return 0;
}