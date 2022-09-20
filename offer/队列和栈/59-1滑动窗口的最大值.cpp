#include<bits/stdc++.h>
using namespace std;
// 超时
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
// 维护map+大顶堆
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        priority_queue<int> bigheap;
        unordered_map<int, int> mp;
        vector<int> res;
        if(size == 0) return res;
        unsigned int n = num.size();
        if(size > n) return res;
        for(int i = 0; i < min(size, n); ++i) {
            bigheap.push(num[i]);
            mp[num[i]]++;
        }
        res.push_back(bigheap.top());
        for(int i = size; i < n; ++i) {
            bigheap.push(num[i]);
            mp[num[i]]++;
            mp[num[i - size]]--;
            while(mp[bigheap.top()] < 1) {
                bigheap.pop();
            }
            res.push_back(bigheap.top());
        }
        return res;
    }
};
// 维护一个单调的双端队列 从左到右递增
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