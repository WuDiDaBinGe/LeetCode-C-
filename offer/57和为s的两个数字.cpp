#include<bits/stdc++.h>
using namespace std;
// 双指针
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0,  right = n -1;
    while(left < right) {
        if(nums[left] + nums[right] == target) {
            return {nums[left], nums[right]};
        } else if (nums[left] + nums[right] < target) {
            left = left + 1;
        } else {
            right = right - 1;
        }
    }
    return {-1, -1};
}
int main() {
    return 0;
}