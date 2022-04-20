#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> result;
    int left = 0, right = k - 1;
    int curMax = *max_element(nums.begin(), nums.begin() + k);
    while(right < n) {
        
        left++;
        right++;
    }
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
    return 0;
}