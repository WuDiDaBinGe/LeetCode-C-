#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// 空间复杂度o(1)
int findRepeatNumber(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        int value = nums[i];
        if(value == i) continue;
        while(nums[i] != i) {
            if(nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[nums[i]], nums[i]);
        }
    }
    return -1;
}
// 普通的hash解法
int findRepeatNumber(vector<int>& nums) {
    int n = nums.size();
    vector<int> hash(n, 0);
    for(int i = 0; i < n; i++) {
        hash[nums[i]]++;
        if(hash[nums[i]] > 1) return nums[i];
    }
    return -1;
}