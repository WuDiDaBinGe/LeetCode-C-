#include<vector>
#include<iostream>
using namespace std;
int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int left = 0;
        int max_pos = nums[0], step = 1;
        while(max_pos < n - 1) {
            // 能达到的新的最远的距离
            int new_max_level = max_pos;
            for(int i = left; i <= max_pos; i++) {
                new_max_level = max(i + nums[i], new_max_level);
            }
            left = max_pos;
            step++;
            max_pos = new_max_level;
        }
        return step;
}