#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_level = 0;
        int n = nums.size();
        if(n == 1) return true;
        for(int i = 0; i <= max_level && i <n; i++) {
            max_level = max(i + nums[i], max_level);
        }
        return max_level >= n - 1;
    }
};