#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if(n < 3) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; ++i) {
            if(nums[i] > 0) return res;
            if(i > 0 && nums[i] == nums[i - 1])    
                continue;        
            int left = i + 1, right = n - 1;
            while(left < right) {
                int n = nums[left] + nums[right];
                if(n == -nums[i]) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    res.push_back(tmp);
                    left++, right--;
                    // 防止重复
                    while(left < n  && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while(right >= 0 && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } 
                else if(n < -nums[i]) {
                    left = left + 1;
                }
                else {
                    right = right - 1;
                }
            }
        }
        return res;
    }
};