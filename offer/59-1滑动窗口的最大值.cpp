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
int main() {
    return 0;
}